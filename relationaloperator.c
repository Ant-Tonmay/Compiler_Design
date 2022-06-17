#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h>

void showIdentifiers(int arr[][2], int row, const char str[]) {
  printf("Relational Operators are: \n");
  for (int i = 0; i < row; i++) {
    for (int j = arr[i][0]; j <= arr[i][1]; j++) {
      printf("%c", str[j]);
    }
    printf("\n");
  }
}

bool isLetter(char ch) {
  return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}
bool isNumber(char ch) { return (ch >= '0' && ch <= '9'); }

bool isOperator(char ch) {

  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' ||
          ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']' 
         || ch == '%' || ch == '^' || ch == '"' || ch == ','||ch==';');    
}

bool isRelationalOperator(char ch){
    return (ch=='<'||ch=='>'||ch=='!'||ch=='=');
}

bool isSpace(char ch) { return (ch == ' '); }

bool isBitwise(char ch){
  return (ch=='|' || ch=='&');
}



////////

void relationalOperator(const char* str){
  printf("Input string is : %s \n",str);
  char  state ='A';
  int array[100][2] , row = 0 , start = 0;
  for(int i=0 ; str[i]!='\0' ; i++)
{
  switch (state) {
    case 'A':
      if(str[i]=='>'||str[i]=='<')
      {
        start=i;
        state = 'B';
      }
      else if(str[i]=='='||str[i]=='!')
      {
        start =i;
        state = 'F';
      }
      else {
       state = 'A';
      }
      break;
    
    case 'B':
      if(isLetter(str[i])||isNumber(str[i])||isSpace(str[i])){
        state='C';
        array[row][0]=start;
        array[row][1]=i-1;
        row++;
      }
      else if (str[i]=='=') {
          state ='D';
      }
      else {
        state ='E';
      }
      break;

    case 'C':
      
      if (isLetter(str[i])||isNumber(str[i])||isOperator(str[i])||isSpace(str[i])||isRelationalOperator(str[i])||isBitwise(str[i])) {
        state = 'A';
      }
      break;

    case 'D':
      if(isLetter(str[i])||isNumber(str[i])||isSpace(str[i]))
      {
        state = 'C';
        array[row][0]=start;
        array[row][1]=i-1;
        row++;
      }
      else {
       state='E';
      }
      break;

    case 'E':
      if (isLetter(str[i])||isNumber(str[i])||isOperator(str[i])||isBitwise(str[i])) {
       state='A';
      }
      else {
       state='E';
      }
      break;

    case 'F':
      if(str[i]=='=')
      {
        state='D';
      }
      else {
       state='E';
      }
      break;
  }

}

showIdentifiers(array,row,str);
  
}

void endToEndTest(){

relationalOperator("if(a==b)||(c>=d");
relationalOperator("if(a=>!=b)||(c===d)||(c==d");
relationalOperator("if(a!=b)||(c>=d");
relationalOperator("if(a<=b)||(c>=d)||(a==c)||(a>b)||(a<c)||(a==!>+d)");


}

int main() {

endToEndTest();
 

}