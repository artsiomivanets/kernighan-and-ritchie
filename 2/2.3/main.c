#include <stdio.h>

int htoi(char *string) {
  int i, n, temp;
  i = n = temp = 0;
  for(; string[i] != '\0'; i++) {
    if (string[i] == '0' && (string[i + 1] == 'x' || string[i + 1] == 'X')) {
      i++;
      continue;
    }
    if (string[i] >= '0' && string[i] <= '9') {
      temp = string[i] - '0';
    }
    if (string[i] >= 'a' && string[i] <= 'f') {
      temp = string[i] - 'a' + 10;
    }
    if (string[i] >= 'A' && string[i] <= 'F') {
      temp = string[i] - 'A' + 10;
    }

    n = 16 * n + temp;
  }

  return n;
}

int main() {
  int result;
  result = htoi("0x0A");
  return printf("%d\n", result);
}
