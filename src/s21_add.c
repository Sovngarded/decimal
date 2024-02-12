#include "s21_decimal.h"
#include <stdio.h>

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){

//     s21_big_decimal value_big_1 = convert_to_big_decimal(value_1);
//     s21_big_decimal value_big_2 = convert_to_big_decimal(value_2);
//     s21_big_decimal result_big = convert_to_big_decimal(*result);

//     if (is_zero(value_1) == TRUE) {
//         printf("zerro");
//         *result = value_2;
//         printf("result = %d %d %d %d =", result->bits[0], result->bits[1], result->bits[2], result->bits[3]);
//         return OK;
//     } else if (is_zero(value_2) == TRUE) {
//         printf("zerro");
//         *result = value_1;
//         return OK;
//     }

//     printf("start val1 = %d %d %d %d =\n", value_big_1.bits[0], value_big_1.bits[1], value_big_1.bits[2], value_big_1.bits[3]);
//     printf("start val2 = %d %d %d %d =\n", value_big_2.bits[0], value_big_2.bits[1], value_big_2.bits[2], value_big_2.bits[3]);

//     int s = normalize_scale(value_1, value_2);
//     value_big_1 = set_scale_and_number(value_big_1, s21_get_scale(value_1), s);
//     value_big_2 = set_scale_and_number(value_big_2, s21_get_scale(value_2), s);

//     printf("\nval1 = %u %u %u %u =\n", value_big_1.bits[0], value_big_1.bits[1], value_big_1.bits[2], value_big_1.scale);
//     printf("val2 = %u %u %u %u =\n", value_big_2.bits[0], value_big_2.bits[1], value_big_2.bits[2], value_big_2.scale);


//     if(s21_get_sign(value_1) == s21_get_sign(value_2)){
//         for(int i=0; i < 3; i++) {
//             result_big.bits[i] = value_big_1.bits[i] + value_big_2.bits[i];
//         }
//         //return OK;
//     } else {
//         if(s21_is_less(value_1, value_2) == TRUE) {
//             for(int i=0; i < 3; i++) {
//                 result_big.bits[i] = value_big_2.bits[i] - value_big_1.bits[i];
//             }
//         } else {
//             for(int i=0; i < 3; i++) {
//                 result_big.bits[i] = value_big_1.bits[i] - value_big_2.bits[i];
//             }
//         }
//         //return OK;
//     }

//     int sc = s <<= 16;
//     printf("s<<=16 = %d", sc);
//     result_big.scale = sc;
//     printf("result_big.scale = %d", result_big.scale);

//     result_big.bits[3] = result_big.scale;
//     printf("result_big.bits[3] = %d", result_big.bits[3]);


//     //is_overflow_pointer(&result_big);
    
//     printf("result big = %LU %LU %LU %LU  =\n", result_big.bits[0], result_big.bits[1], result_big.bits[2], result_big.bits[3]);
    
//     *result = convert_to_decimal(result_big);

//     printf("result = %LU %LU %LU %LU  =", result->bits[0], result->bits[1], result->bits[2], result->bits[3]);
//     ///*result = re

//     return OK;                                                                                                                   
// }

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {

    if (is_zero(value_1) == TRUE) {
        printf("zerro");
        *result = value_2;
        printf("result = %d %d %d %d =", result->bits[0], result->bits[1], result->bits[2], result->bits[3]);
        return OK;
    } else if (is_zero(value_2) == TRUE) {
        printf("zerro");
        *result = value_1;
        printf("result = %d %d %d %d =", result->bits[0], result->bits[1], result->bits[2], result->bits[3]);
        return OK;
    }

    s21_big_decimal value_big_1 = convert_to_big_decimal(value_1);
    s21_big_decimal value_big_2 = convert_to_big_decimal(value_2);
    s21_big_decimal result_big = convert_to_big_decimal(*result);

    printf("start val1 =  %LU %LU %LU %LU  =\n", value_big_1.bits[0], value_big_1.bits[1], value_big_1.bits[2], value_big_1.bits[3]);
    printf("start val2 =  %LU %LU %LU %LU =\n", value_big_2.bits[0], value_big_2.bits[1], value_big_2.bits[2], value_big_2.bits[3]);
   
   
    int scale_1 = s21_get_scale(value_1);
    int scale_2 = s21_get_scale(value_2);

    int needed_scale = normalize_scale(value_1,value_2);
    value_big_1  = set_scale_and_number( value_big_1 , scale_1, needed_scale);
    value_big_2 = set_scale_and_number( value_big_2, scale_2, needed_scale);

    if(s21_get_sign(value_1) == s21_get_sign(value_2)){
        for(int i=0; i < 3; i++) {
            result_big.bits[i] = value_big_1.bits[i] + value_big_2.bits[i];
        }
        //return OK;
    } else{ 
            for(int i = 0;i<3;i++){
                if(value_1.bits[i] > value_big_2.bits[i]){ 

                    result->bits[i] = value_big_1.bits[i] - value_big_2.bits[i];


                } else {
                    result->bits[i] = value_big_2.bits[i] - value_big_1.bits[i];
                }

                }
            }

    int sc = s <<= 16;
    printf("s<<=16 = %d", sc);
    result_big.scale = sc;
    printf("result_big.scale = %d", result_big.scale);

    result_big.bits[3] = result_big.scale;
    printf("result_big.bits[3] = %d", result_big.bits[3]);


    // is_overflow_pointer(&result_big);
    
    printf("result big = %LU %LU %LU %LU  =\n", result_big.bits[0], result_big.bits[1], result_big.bits[2], result_big.bits[3]);

    return OK;
    // else {

    
    //     for(int i = 0;i<3;i++){
    //             if(value_1.bits[i] > value_2_b.bits[i]){ 
    //                 result->bits[i] = value_1_b.bits[i] - value_2_b.bits[i];
    //             } else {
    //                 result->bits[i] = value_2_b.bits[i] - value_1_b.bits[i];
    //             }
    //             }
    // }


}