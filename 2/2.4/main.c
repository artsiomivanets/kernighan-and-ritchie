#include <stdio.h>

void squeeze(char *s1, char *s2) {
  int i, j;
  int current_position;

  current_position = i = j = 0;

  while (s1[i] != '\0') {
    while (s2[j] != '\0') {
      if (s1[i] == s2[j]) {
        j = 0;
        i++;
      } else {
        j++;
      }
    }
    j = 0;
    s1[current_position++] = s1[i++];
  }

  s1[+current_position] = '\0';
}

int main() {
  int result;
  char buf[] = "ababadacabbaaad";
  squeeze(buf, "ac");
  return printf("%s\n", buf);
}
