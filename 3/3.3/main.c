#include <stdio.h>

#define BEGIN 1
#define INSIDE 2
#define OUTSIDE 3
#define END 4

int state;


void determine_state(char c) {
  switch (state) {
    case OUTSIDE:
      state = c != '-' ? BEGIN : INSIDE;
      return;
    case BEGIN:
      state = INSIDE;
      return;
    case INSIDE:
      state = c != '-' ? END : INSIDE;
      return;
    case END:
      state = c != '-' ? BEGIN : OUTSIDE;
  }
}

void expand(char *s1, char *s2) {
  int i, j, last;
  char c, from, to;
  state = OUTSIDE;
  last = 0;

  for(i = 0; s1[i] != '\0'; i++) {
    c = s1[i];
    determine_state(c);
    switch (state) {
      case BEGIN:
        from = c;
        break;
      case END:
        to = c;
        for(j = from; j <= to; j++) {
          s2[last] = j;
          last++;
        }
    }
  }
}

int main() {
  int c;
  char s[50];

  expand("a-c3-6e-i", s);

  printf("%s", s);
}
