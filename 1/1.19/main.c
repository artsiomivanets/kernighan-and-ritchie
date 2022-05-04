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


void reverse(char *line, int size) {
  for(int i = size - 1; i >= 0; --i) {
    putchar(line[i]);
  }
}

int main() {
  char buf[1000];
  int size;
  while((size = ggetline(buf)) > 0)
    reverse(buf, size);

  return 1;
}





