#include "s21_decimal.h"

// < nado fix sdelat chto kogda ravno ono toje 0 vozvrashaet
int s21_is_less(s21_decimal value_1, s21_decimal value_2){  
    int result = TRUE;

    s21_big_decimal value_1_b = convert_to_big_decimal(value_1);
    s21_big_decimal value_2_b = convert_to_big_decimal(value_2);
    
    int scale_1 = s21_get_scale(value_1);
    int scale_2 = s21_get_scale(value_2);

    int needed_scale = normalize_scale(value_1, value_2);
    value_1_b = set_scale_and_number(value_1_b, scale_1, needed_scale);
    value_2_b = set_scale_and_number(value_2_b, scale_2, needed_scale);


    int sign_1 = s21_get_sign(value_1);
    int sign_2 = s21_get_sign(value_2);
    
    int flag = TRUE;
    for(int i = 6; i >= 0; i--) {
            if (value_1_b.bits[i] != 0 || value_2_b.bits[i] != 0) {
                flag = FALSE;
            }
        }
        if (flag == TRUE) {
            return FALSE; 
        }

    if(sign_1 == sign_2) { 
        for(int i = 6; i >= 0; i--){
            if (value_1_b.bits[i] != 0 || value_2_b.bits[i] != 0) {
                if(value_1_b.bits[i] > value_2_b.bits[i]) {
                    result = FALSE;
                    if(sign_1 == 1) {
                        result = TRUE;
                    }
                    break;
                } else if (sign_1 == 1 ) {
                    result = FALSE;
                    break;
                } else if (sign_1 == 0 && value_1_b.bits[i] != value_2_b.bits[i]) {
                    result = TRUE;
                    break;
                }
            } 
            // else if (value_1_b.bits[i] != value_2_b.bits[i]) {
            //         if (sign_1 == 1 )
            //         {
            //             result = FALSE;
            //         } else if (sign_1 == 0) {
            //             result = TRUE;
            //         }
            //         break;
            //     } 
        }
    } else {
        if (sign_1 == 0) {
            result = FALSE;
        }
    }
    return result;
}