#include "s21_decimal.h"
#include <stdio.h>

// int is_overflow_pointer(s21_big_decimal* big_number) {
//     int result = FALSE;
//     int overflow = 0;
//     s21_big_decimal copy_num = *big_number;
//     for(int i = 0; i < 7; i++) {
//         copy_num.bits[i] += overflow;
//         overflow = copy_num.bits[i] >> 32;
//         copy_num.bits[i] &= MAX4BITE;
//     }
//     if(overflow != 0) {
//         result = TRUE;
//     } else {
//         *big_number = copy_num;
//     }
//     return result;
// }

// #include "s21_decimal.h"

int is_overflow_pointer(s21_big_decimal* big_number) {
    int result = FALSE;
    int overflow = 0;
    for(int i = 0; i < 7; i++) {
        big_number->bits[i] += overflow;
        overflow = big_number->bits[i] >> 32;
        big_number->bits[i] &= MAX4BITE;
    }
    if(overflow != 0) {
        result = TRUE;
    }
    return result;
}


s21_big_decimal left_shift(s21_big_decimal big_number) {
     s21_big_decimal copy_num = big_number;
    for(int i = 0; i < 7; i++) {
        copy_num.bits[i] *= 10;
    }
    printf("bit[0] = %LU bit[1] = %LU bit[2] = %LU", copy_num.bits[0], copy_num.bits[1], copy_num.bits[2]);
    
    s21_big_decimal* copy_num_pointer = &copy_num;

    if(is_overflow_pointer(copy_num_pointer) == FALSE) {
        big_number = copy_num;
        big_number.scale++;
    } else {
        printf("OVERFLOWWW");
    }

    return big_number; // ???
}