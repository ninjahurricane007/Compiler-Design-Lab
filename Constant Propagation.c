#include<stdio.h>
#include<ctype.h>
int n;
char prod[10][20];
void input()
{
    int i;
    printf("Enter number of productions : ");
    scanf("%d",&n);
    printf("\nEnter %d productions : \n",n);
    for(i=0;i<n;i++)
    {
        scanf("%s",prod[i]);
    }
}
void replace(char c ,char num, int no)
{
    int i;
    for(i=no+1;i<n;i++)
    {
        int j=2;
        if(prod[i][0]==c)
            break;
        while(prod[i][j]!='\0')
        {
            if(prod[i][j]==c)
            {
                prod[i][j]=num;
                break;
            }
        j++;
        }
    }
}
void check()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(isdigit(prod[i][2]) && prod[i][3]=='\0')
        {
            replace(prod[i][0],prod[i][2],i);
            prod[i][0]='#';
        }
    }
}
void display()
{
    for(int i=0;i<n;i++)
    {
        if(prod[i][0]!='#')
        {
            printf("%s\n",prod[i]);
        }
    }
}
void main()
{
    input();
    check();
    printf("\nOptimised code is : \n");
    display();
}