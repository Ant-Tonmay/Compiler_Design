#include<stdio.h>
int main (){
    char str[100] , state ='A';
    printf("Enter any String Over {0,1}\n");
    scanf("%s",str);

    for (int i = 0; str[i]!=0; i++)
    {
        switch (state)
        {
        case 'A':
            if(str[i]=='0'){
                state = 'B';
            }
            else if(str[i]=='1')
            {
                state ='E';
            }
            else{
                printf("Invalid String");
                return 0;
            }
            break;

        case 'B':
            if(str[i]=='0')
            {
                state = 'C';
            }
            else if(str[i]=='1')
            {
                state = 'B';
            }
            else{
                printf("Invalid String");
                return 0;
            }
            break;

        case 'C':
            if(str[i]=='0')
            {
                state = 'B';
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
            
        case 'D': 
            if(str[i]=='0'){
                state = 'B';
            }
            else if (str[i]=='1')
            {
                state = 'D';
            }
            else {
                printf("Invalid String");
                return 0;
            }
            break;

        case 'E':
            if(str[i]=='0'){
                state = 'B';
            }
            else if(str[i]=='1'){
                state = 'E';
            }
            else{
                printf("Invalid String");
                return 0;
            }
            break;;
        }


    }
    if(state=='C'||state=='D'){
        printf("String is accepted by the Matchine");
    }
    else{
        printf("String is not accepted by the Matchine");
    }
    
    return 0;
    
}