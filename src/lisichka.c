#include "s21_decimal.h"
#include <stdio.h>

int s21_get_sign(s21_decimal number) {
        int sign = number.bits[SCALE] & MINUS;
        return sign;
    }

void s21_set_sign(s21_decimal *number, int sign) {
    if(sign == 1){
        number->bits[SCALE] |= MINUS;
    }
    if(sign == 0){
        number->bits[SCALE] &= ~MINUS;
    }
}

// int s21_get_bit(s21_decimal number, int bit_position) {
//     int mask = (1u <<= (bit_position % 32));
//     printf("mask =%u=\n", mask);
//     int bit = number.bits[bit_position/32] & mask;
//     printf("bit=%d=\n", bit);
//     printf("bit=%d=\n", bit != 0);

//     return (number.bits[bit_position / 32] & mask) != 0;
// }

int s21_get_bit(s21_decimal number, int bit_position) {
    int bit = (number.bits[bit_position / 32] >>  bit_position % 32) & 1u;
    return bit;
}

void s21_set_bit(int *number, int bit_position, int bit) {
    int mask = 1; 
    mask <<= bit_position;

    if(bit == 0) {
        mask = ~mask;
        *number &= mask;
    }

    if(bit == 1) {
        *number |= mask;
    }
}

int is_zero(s21_decimal number) {
    int result = FALSE;
    if(number.bits[LOW] == 0 && number.bits[MID] == 0 && number.bits[HIGH] == 0) {
        result = TRUE;
    }
    return result;
}

int is_overflow(s21_big_decimal big_number) {
    int result = FALSE;
    int overflow = 0;
    for(int i = 0; i < 7; i++) {
        big_number.bits[i] += overflow;
        overflow = big_number.bits[i] >> 32;
        big_number.bits[i] &= MAX4BITE;
    }
    if(overflow != 0) {
        result = TRUE;
    }
    return result;
}

void left_shift(s21_big_decimal* big_number) {
     s21_big_decimal copy_num = *big_number;
    for(int i = 0; i < 7; i++) {
        copy_num.bits[i] *= 10;
    }

    if(is_overflow(*big_number) != TRUE) {
        big_number->scale++;
        *big_number = copy_num;
    }
}

int right_shift(s21_big_decimal* big_number) {
    int remainder = 0;
    for(int i = 6; i < 0; i--) {
        big_number->bits[i] += remainder << 32;
        remainder = big_number->bits[1] % 10;
        big_number->bits[i] /= 10;
    }
    big_number->scale--;
    return remainder;
}

// int main() {
//     // 0.00000
//     s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x50000}};
//     // 0
//     s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

//     s21_decimal number = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
//     printf("%d\n", s21_get_bit(number, 5));
//     return 0;
// }

