#include <stdio.h>
#define BUF_SIZE 1024

int main() {
  FILE *input = fopen("input.txt", "r");

  char buffer[BUF_SIZE];
  int sum = 0;

  while (fgets(buffer, BUF_SIZE, input) != NULL) {
    int first = -1;
    int second = -1;

    for (int i = 0; buffer[i] != '\0'; i++) {
      if ('1' <= buffer[i] && buffer[i] <= '9') {
        if (first == -1) {
          first = buffer[i];
        }
        second = buffer[i];
      }
    }
    sum += (first - '0') * 10 + (second - '0');
  }

  if (feof(input) != 0) {
    printf("%d\n", sum);
  } else {
    printf("error with fgets\n");
  }

  fclose(input);

  return 0;
}
