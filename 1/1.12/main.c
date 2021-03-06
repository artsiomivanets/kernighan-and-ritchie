#include <stdio.h>

#define IN 1
#define OUT 2


int main() {
  int c, state;
  state = IN;

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        state = OUT;
        putchar('\n');
      }
    } else {
      state = IN;
      putchar(c);
    }
  }
  return 1;
}
