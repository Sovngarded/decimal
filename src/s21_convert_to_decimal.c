#include "s21_decimal.h"

s21_decimal s21_convert_to_decimal(s21_big_decimal value_1){
   s21_decimal result;


    for(int i = 0;i<3;i++){
    result.bits[i] = value_1.bits[i] & MAX4BITE;
    }
    result.bits[3] |= (value_1.scale << 16);

    return result; 
}
