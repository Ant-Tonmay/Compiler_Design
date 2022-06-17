#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int identifierDetector(const char *str);
bool isLetter(char ch) {
  return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}

bool isNumber(char ch) { return (ch >= '0' && ch <= '9'); }

bool isOperator(char ch) {

  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' ||
          ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '{' ||
          ch == '}' || ch == '[' || ch == ']' || ch == '&' || ch == '%' ||
          ch == '^'||ch=='"'||ch==',');
}
bool isSpace(char ch) { return (ch == ' '); }

bool isDollar(char ch) { return (ch == '$'); }

void showIdentifiers(int arr[][2], int row, const char *str) {
  printf("Identifiers are: \n");
  for (int i = 0; i < row; i++) {
    for (int j = arr[i][0]; j <= arr[i][1]; j++) {
      printf("%c", str[j]);
    }
    printf("\n");
  }
}

void unitTest() {
  if (isNumber('9'))
    printf("is number test pass\n");
  if (isNumber('a'))
    printf("is number test fail\n");
  if (isDollar('$'))
    printf("is dollar test pass\n");
  if (isLetter(9))
    printf("is letter test fail\n");
  if (isLetter('a'))
    printf("is letter test pass\n");
  if (isOperator('>'))
    printf("is operator pass\n");
  if (isOperator('a'))
    printf("is operator test fail\n");
  if (isSpace(' '))
    printf("is space test pass\n");
}
void endToEndTest() {
  identifierDetector("scanf(\"%d\",&a$)");
  identifierDetector("int x$ = y$+z$");
  identifierDetector("int x$ = 10$+5c$");
  identifierDetector("int x = c5+5C5$");
  identifierDetector("int x = c5$+1$");
  identifierDetector("int x$ = ($$){}[$] ");
  identifierDetector("int x$ = A$+           V$ ");
}

void goToStateA(int *start, int i, const char *str) { *start = i + 1; }

void goToStateC(int array[][2], const char *str, int *row, int i, int start) {

  array[*row][0] = start;
  array[*row][1] = i - 1;
  (*row)++;
}

int main() { endToEndTest(); }

int identifierDetector(const char *str) {
  printf("Input String is: %s \n",str);
  int array[100][2];
  int start = 0;
  int row = 0;
  char state = 'A';

  for (int i = 0; str[i] != '\0'; i++)

  {
    switch (state) {

    case 'A':

      if (isSpace(str[i])) {
        state = 'A';

        goToStateA(&start, i, str);
      } else if (isLetter(str[i])) {
        state = 'B';
      } else if (isOperator(str[i]) || isDollar(str[i]) || isNumber(str[i])) {
        state = 'D';
      } else {
        printf("%c\n", str[i]);
        printf("Invalid token Found!\n");
        return 0;
      }
      break;

    case 'B':

      if (isSpace(str[i]) || isOperator(str[i])) {
        state = 'A';

        goToStateA(&start, i, str);
      } else if (isLetter(str[i]) || isNumber(str[i])) {
        state = 'B';
      } else if (isDollar(str[i])) {
        state = 'C';

        goToStateC(array, str, &row, i, start);
      } else {
        printf("%c", str[i]);
        printf("Invalid token Found!\n");
        return 0;
      }

      break;

    case 'C':

      if (isSpace(str[i]) || isOperator(str[i])) {
        state = 'A';
        goToStateA(&start, i, str);
      } else if (isLetter(str[i])) {
        state = 'B';
      } else if (isNumber(str[i]) || isDollar(str[i])) {
        state = 'D';
      } else {
        printf("%c", str[i]);
        printf("Invalid token Found!\n");
        return 0;
      }

      break;

    case 'D':

      if (isSpace(str[i]) || isOperator(str[i])) {
        state = 'A';

        goToStateA(&start, i, str);
      } else if (isNumber(str[i]) || isDollar(str[i]) || isLetter(str[i])) {
        state = 'D';
      } else {
        printf("%c", str[i]);
        printf("Invalid token Found!\n");
        return 0;
      }
      break;
    }
  }

  showIdentifiers(array, row, str);

  return 0;
}
