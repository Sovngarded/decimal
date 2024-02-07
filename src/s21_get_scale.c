#include "s21_decimal.h"
#include <stdio.h>

int s21_get_scale(s21_decimal s21_decimal){
//  s21_decimal decimal1 = {{0x00190000, 0, 0, 0}};
 int scale = s21_decimal.bits[3] & SCALEBITE;
//  int new = scale >>16;
 scale >>= 16;

 printf("s21_get_scale = %d", scale);
 return scale;
//  printf("%d",scale);
}