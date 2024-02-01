

#include <stdio.h>
#include "s21_decimal.h"








int main(){

// --------------------- get scale -----------------------
//  s21_decimal decimal1 = {{0x00190000, 0, 0, 0}};
//  int scale = decimal1.bits[0] & SCALEBITE;
// //  int new = scale >>16;
//  scale >>= 16;
//  printf("%d",scale);

// --------------------- set scale -----------------------

s21_decimal decimal1 =  {{0x00000000, 0x00000000, 0x00000000, 0x140000}};
int scale = decimal1.bits[3] & SCALEBITE;
printf("%d", scale >> 16); 
int new_scale = 0x001C;
decimal1.bits[3] &= MINUS;
decimal1.bits[3] |= ((new_scale<<16) & SCALEBITE);
scale = decimal1.bits[3] & SCALEBITE;
printf("\n%d", scale >> 16); 
// printf("%d", new_scale); 








}