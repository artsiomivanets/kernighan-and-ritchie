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

int getinput(char *buf) {
  int size, full_size;
  size = full_size = 0;
  char *ptr;
  ptr = buf;
  while((size = ggetline(ptr)) > 0) {
    full_size += size;
    ptr += size;
  }
  return full_size;
}

int detab(char *from, char *to, int tab_size) {
  char c;
  int i, offset;
  i = offset = 0;

  while((c = from[i]) != '\0') {
    printf("%s\n", to);
    printf("From index: %d, Char: %c, To offset: %d\n", i, c, offset);
    if (c == '\t') {
      for(int j = 0; j < tab_size; ++j)
        to[offset + j] = ' ';
      offset += tab_size;
    } else {
      to[offset] = c;
    }
    ++i;
    ++offset;
  }
  to[offset] = '\0';
  return offset;
}

int main() {
  char input_buf[10];
  char output_buf[10];
  for(int i = 0; i < 10; i++)
    output_buf[i] = ' ';

  int size;
  size = 0;
  size = getinput(input_buf);
  printf("\n");
  detab(input_buf, output_buf, 2);
  printf("%s", output_buf);

  return 1;
}





