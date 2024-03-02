#include "../s21_decimal.h"

int s21_is_less_or_equal(s21_decimal number1, s21_decimal number2)  {
    int is_equal = s21_is_equal(number1, number2);
    int is_less = s21_is_less(number1, number2);

    return is_equal || is_less ? TRUE : FALSE;
}