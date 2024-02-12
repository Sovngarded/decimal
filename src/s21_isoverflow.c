#include "s21_decimal.h"

int is_overflow(s21_big_decimal* big_number) {
    int result = FALSE;
    int overflow = 0;
    for(int i = 0; i < 7; i++) {
        big_number->bits[i] += overflow;
        overflow = (big_number->bits[i] >> 32);
        big_number->bits[i] &= MAX4BITE;
    }
    if(overflow) {
        result = TRUE;
    }
    return result;
}