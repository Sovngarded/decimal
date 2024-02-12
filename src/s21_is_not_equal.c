#include "s21_decimal.h"

int s21_is_not_equal(s21_decimal number1, s21_decimal number2) {
    int is_equal = s21_is_equal(number1, number2);
    //printf("is_equal?? 0 - false 1 -true: result = %d\n!result = %d\n", is_equal, !is_equal);
    //return is_equal == FALSE ? TRUE : FALSE;
    return !is_equal;
}