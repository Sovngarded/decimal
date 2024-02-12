#include "s21_decimal.h"


// int normalize(s21_big_decimal *dec, const int summ, const int sign) {
//   int trash = 0;
//   int error = 0;
//   int last = 0;
//   s21_big_decimal temp_dec = *dec;

//   for (int i = 6; i > 2; i--) {
//     while (temp_dec.bits[i] != 0 && temp_dec.scale > 0) {
//       last = s21_right_shift_normal(&temp_dec);
//       trash += last;
//     }
//     if (((last > 5 || last == 5) && trash > 5) ||
//         (last == 5 && trash == 5 &&
//          (temp_dec.bits[0] % 10) % 2 == 1)) {  // банковское округление
//       if (!sign) {
//         temp_dec.bits[0]++;
//         is_overflow(&temp_dec);
//       }
//     }
//   }


//   if (summ && trash && temp_dec.bits[0] == 0xffffffff &&
//       temp_dec.bits[1] == 0xffffffff && temp_dec.bits[2] == 0xffffffff) {
//     error = 1;
//   }

//   for (int i = 3; i < 7; i++) {
  
//     if (temp_dec.bits[i] != 0 && temp_dec.scale == 0) {
//       error = 1;
//       i = 7;
//     }
//   }

  
//   if (!error) {
//     *dec = temp_dec;
//   }

//   return error;
// }