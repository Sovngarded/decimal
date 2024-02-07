#include "s21_decimal.h"

int normalize_scale(s21_decimal value_1,s21_decimal value_2){
    int result = 0;
    int scale_1 = s21_get_scale(value_1); int scale_2 = s21_get_scale(value_2);
    
    if(scale_1 > scale_2 && scale_1 <= 28) result = scale_1;
    // if(scale_1 > scale_2 && scale_1 > 28) result = 28;
    if(scale_1 > 28 && scale_2 > 28) result = 28;
    if(scale_1 < scale_2 && scale_2 <= 28) result = scale_2;
    // if(scale_1 < scale_2 && scale_2 > 28) result = 28;


    return result;
}