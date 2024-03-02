#include "s21_decimal.h"
#include <stdio.h>

void s21_overflow(s21_big_decimal *big_number) {
    int overflow = 0;
    for(int i = 0; i < 7; i++) {
        big_number->bits[i] += overflow;
        overflow = big_number->bits[i] >> 32;
        big_number->bits[i] &= MAX4BITE;
    }
}

void mul_big_decimal_10(s21_big_decimal *value) {
  for (int i = 0; i < 7; i++) {
    value->bits[i] *= 10;
  }
  s21_overflow(value);
}

int set_equal_scale(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  if (value_1->scale < value_2->scale) {
    while (value_1->scale < value_2->scale) {
      mul_big_decimal_10(value_1);
      value_1->scale++;
    }
  } else if (value_1->scale > value_2->scale) {
    while (value_1->scale > value_2->scale) {
      mul_big_decimal_10(value_2);
      value_2->scale++;
    }
  }

  return 0;
}
// s21_big_decimal set_scale_and_number(s21_big_decimal value_1, int scale, int scale_n){
//     s21_big_decimal result = value_1;
//     printf("scale = %d scale new = %d\n", scale, scale_n);
//     if(scale < scale_n){
//         for(int i = scale; i < scale_n; i++){
//             printf("left\n");
//             result = left_shift(result);
//         }
//     } else if (scale > scale_n) {
//         for(int i = scale;i>=scale_n;i--){
//            result = right_shift_normal(result); 
//         }
//     }
//     return result;
// }