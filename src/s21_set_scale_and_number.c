#include "s21_decimal.h"


s21_big_decimal set_scale_and_number(s21_big_decimal value_1, int scale, int scale_n){
    s21_big_decimal result = value_1;
    if(scale < scale_n){
        for(int i = scale;i<=scale_n;i++){
            left_shift(result);
        }
    }else{
        for(int i = scale;i>=scale_n;i--){
           right_shift_normal(result); 
        }



    }
    



    return result;
}