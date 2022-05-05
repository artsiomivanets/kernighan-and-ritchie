#include <stdio.h>

int any(char *s1, char *s2) {
  int i, j;

  i = j = 0;

  while (s1[i] != '\0') {
    while (s2[j] != '\0') {
      if (s1[i] == s2[j]) {
        return i;
      } else {
        j++;
      }
    }
    i++;
    j = 0;
  }
  return -1;
}

int main() {
  int result;
  char buf[] = "bbdacabbaaad";
  result = any(buf, "e");
  return printf("%d\n", result);
}
