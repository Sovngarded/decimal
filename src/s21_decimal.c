

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

int main(){


    unsigned int x = 5;
    printf("%d\n",x);
    x = (x << 3) + (x << 1);
    printf("%d\n",x);


// --------------------- convert to big decimal -----------------------
  // -8
    s21_decimal decimal1 = {{0x8, 0x0, 0x0, 0x80000000}};
    // 3.6336660283201536
    s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
    // -4.3663339716798464
    s21_decimal check = {{0x7D86E800, 0x9B1F93, 0x0, 0x80100000}};


s21_decimal* decimal3 = malloc(sizeof(int)*4);


// s21_decimal check = {{0xA7FFFC17, 0x9B5C85F2, 0x50C783EB, 0x1C0000}};

// s21_big_decimal decimal2 = {{0,0,0,0,0,0,0}, 0};     
// printf("%d", s21_is_less(decimal1,decimal2));
s21_add(decimal1,decimal2, decimal3);
// printf("%d",s21_is_equal(*decimal3,check));

for(int i = 0; i<4;i++){
    printf("%ld\n", decimal3->bits[i]);
}
printf("\n");

for(int i = 0; i<4;i++){
    printf(" %ld                                      %ld\n", decimal1.bits[i], decimal2.bits[i]);
}





printf("\n --------------------------------------- \n check down \n");
for(int j = 0; j<4;j++){
    printf("%ld\n", check.bits[j]);
}


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