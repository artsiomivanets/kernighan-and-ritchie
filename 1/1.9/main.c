#include <stdio.h>

int main() {
  int c, prev;

  while((c = getchar()) != EOF) {
    if (c == prev && c == ' ') {
    } else {
      putchar(c);
    }
    prev = c;
  }

  return 1;
}
