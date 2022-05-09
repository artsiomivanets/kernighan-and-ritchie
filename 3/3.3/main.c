#include <stdio.h>

#define BEGIN 1
#define INSIDE 2
#define OUTSIDE 3
#define END 4

int state;


void determine_state(char c, char next) {
  if (OUTSIDE) {
    if (c != '-') {
      state = INSIDE;
    }
  }

}

void expand(char *s1, char *s2) {
  int i, j;
  char c;
  state = OUTSIDE;

  for(i = 0; s1[i] != EOF; i++)
    determine_state(s1[i], s1[i + 1]);
}

int main() {
  int c;
  char s[50];


  expand("a-c3-6e-f-i", s);


  printf("%s", s);
}
