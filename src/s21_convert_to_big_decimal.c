#include "s21_decimal.h"

s21_big_decimal convert_to_big_decimal(s21_decimal value_1){
    s21_big_decimal result;


    for(int i = 0;i<3;i++){
    result.bits[i] = value_1.bits[i] & MAX4BITE;
    }


    return result;
}

s21_decimal convert_to_decimal(s21_big_decimal value) {
    s21_decimal result;
    for (int i = 0; i < 4; i++) {
        result.bits[i] = value.bits[i] & MAX4BITE;
    }
    return result;
}