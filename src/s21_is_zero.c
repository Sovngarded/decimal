#include "s21_decimal.h"

int is_zero(s21_decimal number) {
    int result = FALSE;
    if(number.bits[LOW] == 0 && number.bits[MID] == 0 && number.bits[HIGH] == 0) {
        result = TRUE;
    }
    return result;
}

int is_zero_big(s21_big_decimal big_number) {
    int result = TRUE;
     for(int i = 6; i >= 0; i--) {
        if (big_number.bits[i] != 0) {
            result == FALSE;
        }
    }
    return result;
}