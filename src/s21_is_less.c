#include "s21_decimal.h"


// < nado fix sdelat chto kogda ravno ono toje 0 vozvrashaet
int s21_is_less(s21_decimal value_1, s21_decimal value_2){  
    int result = 1;

    s21_big_decimal value_1_b = convert_to_big_decimal(value_1);
    s21_big_decimal value_2_b = convert_to_big_decimal(value_2);
    int scale_1 = s21_get_scale(value_1);
    int scale_2 = s21_get_scale(value_2);




    int needed_scale = normalize_scale(value_1,value_2);
    value_1_b = set_scale_and_number(value_1_b, scale_1, needed_scale);
    value_2_b = set_scale_and_number(value_2_b, scale_2, needed_scale);


    for(int i = 3;i >= 0; i--){
        if(value_1_b.bits[i] > value_2_b.bits[i]){
            result = 0;
            break;
        }
    }
    
return result;

}