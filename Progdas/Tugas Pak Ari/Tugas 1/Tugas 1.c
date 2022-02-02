#include <stdio.h>

void main(void) {
   int i = 3;
   float j = 0.5, k = 5.0, n;

   n = (i + j) * k + (i/j);
   printf("1. (3 + 0.5) x 5.0 + (3 + 0.5) = %.0f", n);
}
