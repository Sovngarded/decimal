#include "s21_decimal.h"
#include <stdio.h>

int s21_get_scale(s21_decimal s21_decimal){
    int scale = s21_decimal.bits[3] & SCALEBITE;
    scale >>= 16;
    return scale;
}

int s21_get_sign(s21_decimal number) {
        int sign = (int) ((number.bits[SCALE] >> 31) & 1u);
        printf("sign = %d", sign);
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