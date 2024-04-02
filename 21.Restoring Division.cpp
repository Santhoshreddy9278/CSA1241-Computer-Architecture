#include <stdio.h>

int main() {
  unsigned int dividend, divisor, quotient = 0;
  int bit_size = sizeof(unsigned int) * 8; 

  printf("Enter dividend: ");
  scanf("%u", &dividend);

  printf("Enter divisor: ");
  scanf("%u", &divisor);

  if (divisor == 0) {
    printf("Error: Division by zero!\n");
    return 1;
  }

  unsigned int remainder = dividend;

  for (int i = 0; i < bit_size; i++) {
    remainder <<= 1;
    quotient <<= 1;

    int sign_remainder = remainder >> (bit_size - 1);
    int sign_divisor = divisor >> (bit_size - 1);

    if (sign_remainder == sign_divisor) {
      remainder -= divisor;
      quotient |= 1;
    } else {
      remainder += divisor;
    }
  }

  printf("Quotient: %u\n", quotient);
  printf("Remainder: %u\n", remainder);

  return 0;
}
