#include <stdio.h>

int main() {
  int c;
  int tabs, blanks, nl;
  tabs = blanks = nl = 0;

  while((c = getchar()) != EOF) {
    c == ' ' &&  ++blanks;
    c == '\n' && ++nl;
    c == '\t' && ++tabs;
  }
  printf("Tabs: %d\n", tabs);
  printf("Blanks: %d\n", blanks);
  printf("New lines: %d\n", nl);
  return 1;
}
