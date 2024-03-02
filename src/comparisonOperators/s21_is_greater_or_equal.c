#include "../s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
    int is_less = s21_is_less(value_1, value_2);
    int is_equal = s21_is_equal(value_1, value_2);

    int result = FALSE;
    if (is_less == FALSE || is_equal == TRUE) {
        result = TRUE;
    }
    return result;
}
