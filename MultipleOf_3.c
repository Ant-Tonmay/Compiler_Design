#include<stdio.h>
int main (){
 char str [100] , state = 'A';
 printf("Enter any String Over {0,1}\n");
 scanf("%s",str);

for (int i = 0; str[i]!='\0'; i++)
{
    switch (state)
    {
    case 'A':
        if (str[i]=='0')
        {
            state = 'A';
        }
        else if(str[i]=='1')
        {
            state = 'B';
        }
        else {
             printf("Invalid String");
             return 0;
        }
        break;
    
    case 'B':
        if(str[i]=='0')
        {
            state='D';
        }
        else if(str[i]=='1'){
            state = 'C';
        }
        else{
             printf("Invalid String");
             return 0;
        }
        break;
    
    case 'C':
        if(str[i]=='0'){
            state = 'C';
        }
        else if(str[i]=='1'){
            state = 'B';
        }
        else {
            printf("Invalid String");
             return 0;
        }
        break;
    
    case 'D':
        if(str[i]=='0'){
            state = 'E';
        }
        else if(str[i]=='1'){
            state = 'F';
        }
        else {
            printf("Invalid String");
             return 0;
        }
        break;

    case 'E':
        if(str[i]=='0'){
            state = 'D';
        }
        else if(str[i]=='1'){
            state = 'C';
        }
        else {
            printf("Invalid String");
             return 0;
        }
        break;

    case 'F':
        if(str[i]=='0'){
            state = 'E';
        }
        else if(str[i]=='1'){
            state = 'G';
        }
        else {
            printf("Invalid String");
             return 0;
        }
        break;

    case 'G':
        if(str[i]=='0'||str[i]=='1'){
            state = 'G';
        }
        else {
            printf("Invalid String");
             return 0;
        }
        break;
    }
}
    if(state=='C'||state=='A'){
        printf("String Is accepted by the Machine");
    }
    else {
        printf("String is Not Accepted by the Machine");
    }
return 0;
}