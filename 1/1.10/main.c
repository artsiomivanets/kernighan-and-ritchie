#include <stdio.h>

int main() {
  int c, prev;

  while((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\b') {
      putchar('\\');
      putchar('b');
    } 
  }

  return 1;
}
