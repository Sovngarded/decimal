
#include "s21_decimal.h"
s21_big_decimal s21_right_shift_normal(s21_big_decimal big_number) {
    long int remainder = 0;
    for(int i = 6; i < 0; i--) {
        big_number.bits[i] += (remainder << 32);
        remainder = big_number.bits[1] % 10;
        big_number.bits[i] /= 10;
    }
    big_number.scale--;
    return big_number;
}