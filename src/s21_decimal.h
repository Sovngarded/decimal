#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#include <stdint.h>
#include "stdint.h"
#define MAX4BITE 0xffffffff
#define MINUS 0x80000000
#define SCALEBITE 0x00ff0000
#define first 0x00000001
#define FALSE 0
#define TRUE 1

typedef struct 
{
    uint64_t bits[7];
    uint16_t scale;
    // int sing;
} s21_big_decimal;

// scale = bits[4] & SCALEBITE;



typedef struct 
{
    unsigned int bits[4];
} s21_decimal;

enum bits {
    LOW,
    MID,
    HIGH,
    SCALE
};

//Arithmetic Operators
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

//Comparison Operators
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

//Convertors and parsers
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

//Another functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);




//BIT
int s21_get_bit(s21_decimal number, int bit_position);
//int s21_get_highest_bit(s21_decimal number);
void s21_set_bit(unsigned int *source_number, int bit_position, int bit);

//SIGN
int s21_get_sign(s21_decimal number);
void s21_set_sign(s21_decimal *number, int sign);

//SCALE
int s21_get_scale(s21_decimal number);
void s21_set_scale(s21_decimal *number, int scale);

s21_decimal s21_convert_to_decimal(s21_big_decimal value_1);
s21_big_decimal convert_to_big_decimal(s21_decimal value_1);
int normalize_scale(s21_decimal value_1,s21_decimal value_2);
s21_big_decimal set_scale_and_number(s21_big_decimal value_1, int scale, int scale_n);

int is_overflow(s21_big_decimal* big_number);

s21_big_decimal s21_right_shift_normal(s21_big_decimal big_number);
int left_shift(s21_big_decimal *big_number);
void point_to_normal(s21_big_decimal *dec1_work, s21_big_decimal *dec2_work);

#endif  //S21_DECIMAL_H