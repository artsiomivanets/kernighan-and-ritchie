#include <stdio.h>


char setbits(int x, int p, int n, int y) {
  char result = x << 3;
  return result;
}

int main() {
  int a = 0b10110110;
  int b = 0b01010011;

  return printf("%02x\n", setbits(a, 3, 4, b));
}
