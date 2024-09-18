#include <stdio.h>
#include <string.h>
#define L_BUF_SIZE 1024
#define W_BUF_SIZE 8

int main() {
  FILE *input = fopen("input.txt", "r");

  char line_buffer[L_BUF_SIZE];
  char word_buffer[W_BUF_SIZE] = "";
  int sum = 0;

  while (fgets(line_buffer, L_BUF_SIZE, input) != NULL) {
    int first = -1;
    int last = -1;
    int num;

    for (int i = 0; line_buffer[i] != '\0'; i++) {
      num = -1;
      if ('1' <= line_buffer[i] && line_buffer[i] <= '9') {
        num = line_buffer[i] - '0';
      } else {
        if (i + 5 < L_BUF_SIZE) {
          strncat(word_buffer, line_buffer + i, 5);
          if (strcmp(word_buffer, "three") == 0) {
            num = 3;
          } else if (strcmp(word_buffer, "seven") == 0) {
            num = 7;
          } else if (strcmp(word_buffer, "eight") == 0) {
            num = 8;
          }
          strcpy(word_buffer, "");
        }
        if (i + 4 < L_BUF_SIZE) {
          strncat(word_buffer, line_buffer + i, 4);
          if (strcmp(word_buffer, "four") == 0) {
            num = 4;
          } else if (strcmp(word_buffer, "five") == 0) {
            num = 5;
          } else if (strcmp(word_buffer, "nine") == 0) {
            num = 9;
          }
          strcpy(word_buffer, "");
        }
        if (i + 3 < L_BUF_SIZE) {
          strncat(word_buffer, line_buffer + i, 3);
          if (strcmp(word_buffer, "one") == 0) {
            num = 1;
          } else if (strcmp(word_buffer, "two") == 0) {
            num = 2;
          } else if (strcmp(word_buffer, "six") == 0) {
            num = 6;
          }
          strcpy(word_buffer, "");
        }
      }
      if (num != -1) {
        if (first == -1) {
          first = num;
        }
        last = num;
      }
    }
    int rownum = first * 10 + last;
    printf("%d\n", rownum);
    sum += rownum;
  }

  if (feof(input) != 0) {
    printf("%d\n", sum);
  } else {
    printf("error with fgets\n");
  }

  fclose(input);

  return 0;
}
