

#include <stdio.h>
#include "s21_decimal.h"
#include <math.h>
#include <stdlib.h>
#define first 0x00000001
#define FALSE 0
#define TRUE 1


int s21_get_sign(s21_decimal number) {
        int sign = number.bits[SCALE] & MINUS;
        return sign;
    }

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








// --------------------- get scale -----------------------

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

int main() {
// --------------------- convert to big decimal -----------------------
// -0.5
    s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x80010000}};
    // 26409387
    s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
    // 26409386.5
    s21_decimal check = {{0xFBDC0A9, 0x0, 0x0, 0x10000}};

s21_decimal* result = malloc(sizeof(s21_decimal)); 

s21_add(decimal1, decimal2, result); 
printf("\ncheck = %d %d %d %d =", check.bits[0], check.bits[1], check.bits[2], check.bits[3]);

///printf("%d", s21_is_less(decimal1,decimal2));

// s21_big_decimal decimal2 = {{0,0,0,0,0,0,0}, 0}


// decimal2.scale = get_scale(decimal1);


// s21_add(decimal1,decimal2,result);

// printf("%d\n%d",check.bits[0],result->bits[0]);


// for(int i = 0;i<3;i++){
//     if(decimal1.bits[i] >= decimal2.bits[i]){
//         printf("true \n");
//     }else{
//         printf("false");
//     }
// }


// for(int i =0 ; i<7;i++){
// for(int j = 0; j<64;j++){
//     if (decimal2.bits[i] & first) printf("1"); else printf("0"); if (j%8 == 0) printf("\n"); ///// check for correct work , but dunno if it's true
//     decimal2.bits[i] >>=1;
// }
// }



}
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