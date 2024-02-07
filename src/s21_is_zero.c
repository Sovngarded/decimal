#include "s21_decimal.h"

int is_zero(s21_decimal number) {
    int result = FALSE;
    if(number.bits[LOW] == 0 && number.bits[MID] == 0 && number.bits[HIGH] == 0) {
        result = TRUE;
    }
    return result;
}