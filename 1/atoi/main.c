#include <stdio.h>

int atoi(char *string) {
  int i, n;
  i = n = 0;
  for(; string[i] != '\0'; i++)
    n = 10 * n + string[i] - '0';

  return n;
}

int main() {
  int result;
  result = atoi("520");
  return printf("%d\n", result);
}
