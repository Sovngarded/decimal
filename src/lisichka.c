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

int s21_get_bit(s21_decimal number, int bit_position) {
    int bit = (number.bits[bit_position / 32] >>  bit_position % 32) & 1u;
    return bit;
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

int main() {
    s21_decimal number = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
    //s21_get_bit(number, 6);
    printf("%d\n", s21_get_bit(number, 5));
    printf("%d\n", s21_get_bit(number, 34));
    printf("%d\n", s21_get_bit(number, 7));
    return 0;
}