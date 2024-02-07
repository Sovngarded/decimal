#include "s21_decimal.h"

int s21_is_not_equal(s21_decimal number1, s21_decimal number2) {
    int is_equal = s21_is_equal(number1, number2);

    return is_equal == FALSE ? TRUE : FALSE;
    //return !is_equal;
}