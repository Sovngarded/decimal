#include "s21_decimal.h"
#include <stdio.h>

s21_big_decimal set_scale_and_number(s21_big_decimal value_1, int scale, int scale_n){
    s21_big_decimal result = value_1;
    printf("scale = %d scale new = %d\n", scale, scale_n);
    if(scale < scale_n){
        for(int i = scale; i <= scale_n; i++){
            printf("left\n");
            result = left_shift(result);
        }
    } else if (scale > scale_n) {
        for(int i = scale;i>=scale_n;i--){
           result = right_shift_normal(result); 
        }
    }
    return result;
}