#include<stdio.h>
int main (){
    char str[100] , state ='A';
    printf("Enter any String Over {0,1}\n");
    scanf("%s",str);
    for (int i = 0; str[i]!='\0'; i++)
    {
        switch (state)
        {
        case 'A':
            if(str[i]=='0'){
                state = 'A';
            }
            else if (str[i]=='1')
            {
                state = 'B';
            }
            else{
                printf("Invalid String");
                return 0;
            }
            break;
    
        case 'B':
            if(str[i]=='0'){
                state = 'C';
            }
            else if (str[i]=='1')
            {
                state = 'B';
            }
            else{
                printf("Invalid String");
                return 0;
            }
            break;

        case 'C':
            if(str[i]=='0'){
                state = 'D';
            }
            else if (str[i]=='1')
            {
                state = 'A';
            }
            else{
                printf("Invalid String");
                return 0;
            }
            break;
        
        case 'D':
            if(str[i]=='0'){
                state = 'D';
            }
            else if (str[i]=='1')
            {
                state = 'D';
            }
            else{
                printf("Invalid String");
                return 0;
            }
            break;
        
        }
    }
    if(state=='D'){
        printf("String is accpeted by the Machine");
    }
    else{
        printf("String Is not accpted");
    }

    return 0;
}