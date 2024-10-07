#include <stdint.h>
#include <stdio.h>
#include "include/int_as_array.h"

int main(int argument_count, char** argument_vector) {
  int error = 0;
  (void) printf("%s] %s) %d- argument_count: %d\n", __FILE__, __FUNCTION__, __LINE__, argument_count);
  (void) temp();

  int *digits = (int*) calloc(3, sizeof(int));
  digits[0] = 9;
  digits[1] = 9;
  digits[2] = 9;
  int n = 3;
  int *returnSize = &n;
  int digitsSize = 3;

  for(int_fast32_t index = 0; index < digitsSize; ++index) {
    (void) printf("%d :", digits[index]);
   }
  (void) printf("\n");

  (void) printf("returnSize: %d\n", *returnSize);

  digits = plusOne(digits, digitsSize, returnSize);

  (void) printf("returnSize: %d\n", *returnSize);
  
  for(int_fast32_t index = 0; index < n; ++index) {
    (void) printf("%d :", digits[index]);
  }
  (void) printf("\n");
  (void) free(digits);


  int *digits_2 = (int*) calloc(4, sizeof(int));
  digits_2[0] = 1;
  digits_2[1] = 9;
  digits_2[2] = 9;
  digits_2[3] = 0;
  int n_2 = 4;
  int *returnSize_2 = &n_2;
  int digitsSize_2 = 4;

  for(int_fast32_t index = 0; index < digitsSize_2; ++index) {
    (void) printf("%d :", digits_2[index]);
   }
  (void) printf("\n");

  (void) printf("returnSize: %d\n", *returnSize_2);

  digits = plusOne(digits_2, digitsSize_2, returnSize_2);

  (void) printf("returnSize: %d\n", *returnSize_2);
  
  for(int_fast32_t index = 0; index < n_2; ++index) {
    (void) printf("%d :", digits_2[index]);
  }
  (void) printf("\n");
  (void) free(digits_2);


  return error;
}
