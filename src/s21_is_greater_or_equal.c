#include "s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
    int is_less = s21_is_less(value_1, value_2);

    return is_less == TRUE ? FALSE : TRUE;
}
