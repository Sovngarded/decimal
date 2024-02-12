#include "s21_decimal.h"


int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){

    s21_big_decimal value_1_b = convert_to_big_decimal(value_1);
    s21_big_decimal value_2_b = convert_to_big_decimal(value_2);
    s21_big_decimal value_3_b = convert_to_big_decimal(*result);
    int scale_1 = s21_get_scale(value_1);
    int scale_2 = s21_get_scale(value_2);
    // int needed_scale = normalize_scale(value_1,value_2);
    point_to_normal(&value_1_b, &value_2_b);
    

    if(s21_get_sign(value_1) == s21_get_sign(value_2)){
        for(int i =0; i<6;i++){
            value_3_b.bits[i] = value_1_b.bits[i] + value_2_b.bits[i];
            is_overflow(&value_3_b);
        }
    }
    else{ 
            for(int i = 0;i<6;i++){
                if(value_1.bits[i] > value_2_b.bits[i]){ 

                    value_3_b.bits[i] = value_1_b.bits[i] - value_2_b.bits[i];


                } else {
                    value_3_b.bits[i] = value_2_b.bits[i] - value_1_b.bits[i];
                }

                }
            }
    *result = s21_convert_to_decimal(value_3_b);
return 0;
}