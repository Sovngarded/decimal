#include <stdio.h>
#include "s21_decimal.h"
#include <math.h>
#include <stdlib.h>
#define first 0x00000001
#define FALSE 0
#define TRUE 1


// int s21_get_sign(s21_decimal number) {
//         int sign = number.bits[SCALE] & MINUS;
//         return sign;
//     }


// void s21_set_sign(s21_decimal *number, int sign) {
//     if(sign == 1){
//         number->bits[SCALE] |= MINUS;
//     }
//     if(sign == 0){
//         number->bits[SCALE] &= ~MINUS;
//     }
// }

// void s21_set_bit(int *number, int bit_position, int bit) {
//     int mask = 1; 
//     mask <<= bit_position;

//     if(bit == 0) {
//         mask = ~mask;
//         *number &= mask;
//     }

//     if(bit == 1) {
//         *number |= mask;
//     }
// }


// int right_shift(s21_big_decimal* big_number) {
//     long int remainder = 0;
//     for(int i = 6; i < 0; i--) {
//         big_number->bits[i] += (remainder << 32);
//         remainder = big_number->bits[1] % 10;
//         big_number->bits[i] /= 10;
//     }
//     big_number->scale--;
//     return remainder;
// }

// --------------------- set scale for decimal-----------------------

// s21_decimal decimal1 =  {{0x00000000, 0x00000000, 0x00000000, 0x140000}};
// int scale = decimal1.bits[3] & SCALEBITE;
// printf("%d", scale >> 16); 
// int new_scale = 0x001C;
// decimal1.bits[3] &= MINUS;
// decimal1.bits[3] |= ((new_scale<<16) & SCALEBITE);
// scale = decimal1.bits[3] & SCALEBITE;
// printf("\n%d", scale >> 16); 
// // printf("%d", new_scale); 

// int main() {

//       // -1431655765.000000000000000001
//     s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//     // -1431655764.999999999999999999
//     s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};

//     int res = s21_is_less(decimal1, decimal2);
//     printf("%lu and %lu = %d", decimal1.bits[LOW], decimal2.bits[LOW], res);

//     return 0;

// }

// --------------------- decimal to int -----------------------
// s21_decimal decimal1 = {{0002, 0002, 0, 0x140000}};
// long long int sum = 0;
// long double m = 0.0;
// for(int i = 0; i<3;i++){
//     for(int j = 0;j<31;j++){
//         if(decimal1.bits[i]>>j & first == 1) sum += powl(2.0,m);          ///// NE RABOTAET SLOJNO :(
//         m++;
//     }

// // }

// }

// printf("%d",sum);

// }