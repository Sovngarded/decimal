#include "s21_decimal.h"


int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){

    s21_big_decimal value_1_b = convert_to_big_decimal(value_1);
    s21_big_decimal value_2_b = convert_to_big_decimal(value_2);


    if(s21_get_sign(value_1) == s21_get_sign(value_2)){
        for(int i =0; i<3;i++){
            result->bits[i] = value_1_b.bits[i] + value_2_b.bits[i];
        }
    }
    else{ 
            for(int i = 0;i<3;i++){
                if(value_1.bits[i] > value_2_b.bits[i]){ 

                    result->bits[i] = value_1_b.bits[i] - value_2_b.bits[i];


                } else {
                    result->bits[i] = value_2_b.bits[i] - value_1_b.bits[i];
                }

                }
            }
    
return 0;
}