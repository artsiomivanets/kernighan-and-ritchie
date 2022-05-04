#include <stdio.h>

#define IN 1
#define OUT 2


int main() {
  int c, i, j, current, state, lengths[11];
  current = 0;
  for(i = 0; i <= 10; ++i)
    lengths[i] = 0;

  state = IN;

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        ++lengths[current];
        current = 0;
        state = OUT;
      }
    } else {
      state = IN;
      ++current;
    }
  }

  for(i = 1; i <= 10; ++i) {
    printf("Length %d: ", i);
    for(j = 1; j <= lengths[i]; ++j)
      printf("|");
    printf("\n");
  }
  return 1;
}
