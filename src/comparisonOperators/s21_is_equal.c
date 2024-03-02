#include "../s21_decimal.h"


int s21_is_equal(s21_decimal value_1, s21_decimal value_2){
    int result = TRUE;
    
    s21_big_decimal value_1_b = convert_to_big_decimal(value_1);
    s21_big_decimal value_2_b = convert_to_big_decimal(value_2);
    int scale_1 = s21_get_scale(value_1);
    int scale_2 = s21_get_scale(value_2);

    int needed_scale = normalize_scale(value_1,value_2);
    value_1_b = set_scale_and_number(value_1_b, scale_1, needed_scale);
    value_2_b = set_scale_and_number(value_2_b, scale_2, needed_scale);

    int sign_1 = s21_get_sign(value_1);
    int sign_2 = s21_get_sign(value_2);
    if(sign_1 == sign_2) {
        for(int i = 0; i < 3;i++){
            if(value_1_b.bits[i] != value_2_b.bits[i]) {
                result = FALSE;
                break;
            }
        }
    } else {
        result = FALSE;
        if(value_1_b.bits[0] == 0 && value_2_b.bits[0] == 0 && value_1_b.bits[1] == 0 && value_2_b.bits[1] == 0 && value_1_b.bits[2] == 0 && value_2_b.bits[2] == 0) {
            result = TRUE;
        }
    }

    return result;
}