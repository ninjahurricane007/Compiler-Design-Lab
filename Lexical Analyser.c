#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int operator_checker(char op);
int special_checker(char sp);
int keyword_checker(char keyword[]);
int main()
{
    FILE *fp,*output;
    char buffer[1000],ch,digit[100],identifier[100];
    int n=0,l=1,t=1,m=0;
    fp=fopen("input.txt","r");
    output=fopen("output.txt","w");
    fprintf(output,"Line no. \t Token no. \t Token \t\t Lexeme\n\n");
    while(!feof(fp)) {
        buffer[n++]=fgetc(fp);
    }
    printf("\nInput file contents are : \n%s",buffer);
    printf("\n");
    int len=strlen(buffer);
    while(m<len){
        ch=buffer[m];
        if(ch=='\n'){
            l++;
        }
        if(operator_checker(ch)==1)
        {
            fprintf(output,"%7d\t\t %7d\tOperator\t%7c\n",l,t,ch);
            t++;
            m++;
            continue;
        }
        if(special_checker(ch)==1){
            fprintf(output,"%7d\t\t %7d\tSpecial symbol\t%7c\n",l,t,ch);
            t++;
            m++;
            continue;
        }
        if(isdigit(ch)){
            int y=0;
            while(isdigit(ch)){
                if(ch==' ' || ch==';')
                    break;
                digit[y++]=ch;
                m++;
                ch=buffer[m];
            }
            digit[y]='\0';
            fprintf(output,"%7d\t\t %7d\tDigit\t\t     %s\n",l,t,digit);
            t++;
            bzero(digit,100);
        }
        else if(isalpha(ch)){
            int y=0;
            while(isalpha(ch)){
                if(ch==' ' || ch==';' || ch==',')
                    break;
                identifier[y++]=ch;
                m++;
                ch=buffer[m];
            }
            if(keyword_checker(identifier)==1){
                fprintf(output,"%7d\t\t %7d\tKeyword\t\t     %s\n",l,t,identifier);
            }
            else{
                fprintf(output,"%7d\t\t %7d\tIdentifier\t\t     %s\n",l,t,identifier);
           }
            t++;
            bzero(identifier,100);
        }
    m++;
    }
return 0;
}
int operator_checker(char op){
    if( op=='+' || op== '-' || op=='*' || op=='/'){
        return 1;
    }
    Else{
        return 0;
    }
}
int special_checker(char sp){
    if( sp==';' || sp=='{' || sp=='}' || sp=='(' || sp==')' || sp=='?' || sp=='@' || sp=='!' || sp=='%')
    {
        return 1;
    }
    else{
        return 0;
    }
}
int keyword_checker(char keyword[])
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    int i, flag = 0;
    for(i = 0; i < 32;i++){
        if(strcmp(keywords[i], keyword) == 0){
            flag = 1;
            break;
        }
    }
return flag;
}