#include "s21_decimal.h"
int left_shift(s21_big_decimal *big_number) {
    s21_big_decimal temp_dec = *big_number;
  for (int i = 0; i < 7; i++) {
    temp_dec.bits[i] *= 10;
  }
  temp_dec.scale++;
  int overflowed = 0;

 
  if (is_overflow(&temp_dec)) {
    overflowed = 1;
  } else {
    *big_number = temp_dec;
  }
  return overflowed;
}