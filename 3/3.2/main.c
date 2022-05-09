#include <stdio.h>

void escape(char *from, char *to) {
  char c;
  int i, j = 0;
  while((c = from[i]) != '\0') {
    switch (c) {
      case '\n':
        to[j] = '\\';
        to[++j] = 'n';
        break;
      case '\t':
        to[j] = '\\';
        to[++j] = 't';
        break;
      default:
        to[j] = c;
    }
    ++i;
    ++j;
  }
  to[++j] = '\0';
}

int main() {
  int c;
  char buf[50];
  char new_buf[50];

  for(int i = 0; i < 50; i++)
    new_buf[i] = ' ';

  for(int i = 0; (c = getchar()) != EOF; i++)
    buf[i] = c;

  escape(buf, new_buf);


  printf("%s", new_buf);
}
