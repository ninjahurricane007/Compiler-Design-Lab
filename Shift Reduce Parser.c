#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char g1[]="E+E";
char g2[]="E*E";
char g3[]="i";
int handle_checker(char stack[],int len);
int main(){
    char expression[30];
    char stack[500],ch;
    char buffer[2];
    buffer[1]='\0';
    int m=0,retval;
    printf("Enter the arithmetic expression : ");
    scanf("%s",expression);
    int len=strlen(expression);
    printf("Stack \t Input \t   Action\n");
    int i=0;
    while(i!=len+1){
        ch=expression[i];
        buffer[0]=ch;
        printf("\n%s",stack);
        printf("\t");
        for(int o=i;o<len;o++){
            printf("%c",expression[o]);}
        printf("\t");
        retval=handle_checker(stack,len);
        if(retval==0){
            strcat(stack,buffer);
            i++;
            printf("  Shift\n");}
        else{
            printf("  Reduce\n");}}
    if(strcmp(stack,"E")==0 && i>=len){
        printf("\nAccepted");}
    else{
        printf("\nRejected");}
return 0;}
int handle_checker(char stack[],int len){
    int i=len-1,m=0,y=1,d;
    char buffer[100];
    while(y==1){
        d=i;m=0;
        while(i!=len){
            buffer[m++]=stack[i];
            i++;}
        if(strcmp(buffer,g1)==0 || strcmp(buffer,g2)==0 || strcmp(buffer,g3)==0){
            i=d;
            while(i!=len){
                stack[i]='\0';
                i++;}
            strcat(stack,"E");
            return 1;}
        bzero(buffer,len);
        i=d;
        i--;
        if(i==-1){
            break;}
    return 0;
}