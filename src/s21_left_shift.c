#include "s21_decimal.h"
s21_big_decimal left_shift(s21_big_decimal big_number) {
     s21_big_decimal copy_num = big_number;
    for(int i = 0; i < 7; i++) {
        copy_num.bits[i] *= 10;
    }

    if(is_overflow(big_number) != TRUE) {
        big_number.scale++;
        big_number = copy_num;
    }
    return big_number; // ???
}