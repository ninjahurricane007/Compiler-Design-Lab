#include<stdio.h>
#include<string.h>
int main()
{
    char exps[20][20],i=0,j=0,op[5];
    int count=1;
    printf("\nEnter the Intermediate codes (exit to stop)\n");
    while(j==0)
    {
        char exp[20];
        scanf("%s",exp);
        if((strcmp(exp,"exit"))==0)
        {
            break;
        }
        strcpy(exps[i++],exp);
    }
    printf("\nThe Assembly code is\n");
    while(j!=i)
    {
        switch(exps[j][3])
        {
            case '+':
            {
                strcpy(op,"ADD");
                break;
            }
            case '-':
            {
                strcpy(op,"SUB");
                break;
            }
            case '/':
            {
                strcpy(op,"DIV");
                break;
            }
            case '*':
            {
                strcpy(op,"MUL");
                break;
            }
        }
        printf("\n\tMOV R%d,%c",count,exps[j][2]);
        printf("\n\t%s R%d,%c",op,count,exps[j][4]);
        printf("\n\tMOV %c,R%d",exps[j][0],count);
        j++;
        count++;
    }
    printf("\n");
    return 0;
}