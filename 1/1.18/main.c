#include <stdio.h>

int ggetline(char *buf) {
  char c;
  int size, i;
  i = size = 0;

  while((c = getchar()) != '\n' && c != EOF) {
    buf[i++] = c;
    ++size;
  }
  if (size == 0 && c == EOF) {
    buf[i] = '\0';
    return size;
  }

  ++size;
  buf[i] = '\n';
  buf[++i] = '\0';

  return size;
}

void copy(char *from, char *to) {
  int i;
  i = 0;
  while((from[i] = to[i]) != '\0')
    ++i;
}


int main() {
  char buf[1000];
  int size;
  while((size = ggetline(buf)) > 0) {
    for(int i = 0; i < size; ++i) {
      if (buf[i] != ' ' && buf[i] != '\t')
        putchar(buf[i]);
    }
  }
  return 1;
}





