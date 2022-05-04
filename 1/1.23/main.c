#include <stdio.h>

#define IN 1
#define OUT 2
#define READY_OUT 5
#define MULTI 3
#define SINGLE 4
int state, type;

void determine_state(char prev, char c, char next) {

  if (state == OUT) {
    if (c == '/' && next == '/') {
      state = IN;
      type = SINGLE;
    } else if (c == '/' && next == '*') {
      state = IN;
      type = MULTI;
    }
  } else if (state == IN) {
    if (prev == '*' && c == '/') {
      state = READY_OUT;
    } else if (type == SINGLE && c == '\n') {
      state = OUT;
    }
  } else if (state == READY_OUT)
    state = OUT;
}

int main() {
  char *str =
    "int main() {\n"
    "  /* some interesting\n"
    "  stuff with mutliline */\n"
    "  int age = 25;\n"
    "  // create some stuff\n"
    "  printf(\"Age: %d\", age);\n"
    "  // great stuff\n"
    "  return 1;\n"
    "}\n";

  state = OUT;
  type = SINGLE;
  int i = 0;
  char c, prev, next;
  c = prev = next =  ' ';

  while((c = str[i]) != '\0') {
    next = str[i + 1];
    determine_state(prev, c, next);
    if (state == OUT)
      putchar(c);
      ++i;
    prev = c;
  }

  return 1;
}





