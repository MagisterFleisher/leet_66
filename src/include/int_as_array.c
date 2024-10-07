#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

void temp(void) {
  (void) printf("%s] %s) %d- Hello, Header!\n", __FILE__, __func__, __LINE__);
  return;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
  /* 
    check if one needs to add a 1 to the next value:
      1) add one to the value, check if equal to 10
      2) add one to value, check if answer mod 10 == 0
      3) check if value which one is adding to equals 9.  Then change to 0 and add 1 to next number.
  */

  /*
     Only in one case will the return array be be longer than the input array:
       all values in array will be 9.
         [9] -> [1, 0]
         [9,9] -> [1, 0, 0]
     Elsewise, one need not worry about a different sized array.
    
    One can ensure that a return array be 
      * the correct size, 
      * not an Variable Length Array (VLA)
      * and more likely to be added to the stack
    by checking if for the [9, 9, ...] case,
      then either calling the function recursively 
      or creating a second function that uses the quasi-VLA notation int* plusOne_new(size_t n, int digits[static n], ...)
    But, this function uses the heap, and so one need only reallocate a larger size, or allocate a second array.
  
  */
  /* if the first value not 9, then no need to worry about spill over.*/
  if(9 != digits[(digitsSize - 1)]) {
    (void) printf("%s) %d- last digit not 9, returning array with last digit++\n", __func__, __LINE__);
    (void) printf("Last digit: %d\n", digits[0]);
    digits[(digitsSize - 1)]++;
    *returnSize = digitsSize; 
    return digits; 
  } else {
    /* check if all elements have value 9 */
    bool is_all_nines = true;
    for(int_fast32_t index = 0; index < digitsSize; index++) {
      if(9 != digits[index]) {
        is_all_nines = false;
      }
    }
    if(!is_all_nines) {
      int remainder = 0;
      if(9 == digits[digitsSize - 1]) {
        remainder = 1;
      }
      for(int_fast32_t index = (digitsSize - 1); index >= 0; index--) {
        if(10 == (digits[index] + remainder)) {
          remainder = 1;
          digits[index] = 0;
        } else {
          digits[index] += remainder;
          remainder = 0;
        }
      }
      *returnSize = digitsSize;
    } else {
      digits = (int*) realloc(digits, (digitsSize + 1) * (sizeof(int)));
      digits[0] = 1;
      for(int_fast32_t index = 1; index <= digitsSize; index++) {
        digits[index] = 0;
      }
      *returnSize = digitsSize + 1;
    }
  }
  return digits;
}