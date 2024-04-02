#include <stdio.h>

int non_restoring_division(unsigned int dividend, unsigned int divisor) {
  unsigned int quotient = 0;
  int i, n = sizeof(dividend) * 8; 

  for (i = n - 1; i >= 0; i--) {
    quotient <<= 1;

    if (dividend << i >= divisor) {
      quotient |= 1; 
      dividend -= divisor; 
    }
  }

  return quotient;
}

int main() {
  unsigned int dividend = 20;
  unsigned int divisor = 4;
  int result = non_restoring_division(dividend, divisor);
  printf("Quotient of %u / %u (non-restoring division): %u\n", dividend, divisor, result);

  return 0;
}
