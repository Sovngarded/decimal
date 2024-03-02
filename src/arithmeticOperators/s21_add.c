#include "../s21_decimal.h"
#include <stdio.h>

//Домножает на 10 не меняя scale
// void mul_big_decimal_10(s21_big_decimal *value) {
//   for (int i = 0; i < 7; i++) {
//     value->bits[i] *= 10;
//   }
//   s21_overflow(value);
// }

// void set_equal_scale(s21_big_decimal *value_1, s21_big_decimal *value_2) {
//   if (value_1->scale < value_2->scale) {
//     while (value_1->scale < value_2->scale) {
//       mul_big_decimal_10(value_1);
//       value_1->scale++;
//     }
//   } else if (value_1->scale > value_2->scale) {
//     while (value_1->scale > value_2->scale) {
//       mul_big_decimal_10(value_2);
//       value_2->scale++;
//     }
//   }
// }

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    
    //нужно проверить число на слишком большое или слишком маленькое 
    if (is_zero(value_1) == TRUE) {
        printf("zerro");
        *result = value_2;
        return OK;
    } else if (is_zero(value_2) == TRUE) {
        printf("zerro");
        *result = value_1;
        return OK;
    }

    s21_big_decimal value_big_1 = convert_to_big_decimal(value_1);
    s21_big_decimal value_big_2 = convert_to_big_decimal(value_2);
    s21_big_decimal result_big = convert_to_big_decimal(*result);

    set_equal_scale(&value_big_1, &value_big_2);
    // result->scale = value_1.scale;

    //int needed_scale = normalize_scale(value_1,value_2);

    return 0;


}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    return 0;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    return 0;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    return 0;
}