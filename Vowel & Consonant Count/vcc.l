%{
#include<stdio.h>
 int vow_count=0;
 int const_count =0;
%}
vow [aeiouAEIOU]
const [a-zA-Z]
%%
{vow} {vow_count++;}
{const} {const_count++;}
%%
int main()
{
 printf("Enter the string : ");
 yylex();
 printf("Number of vowels : %d\n", vow_count);
 printf("Number of consonants : %d\n", const_count);
 return 0;
}
int yywrap()
{
return 1;
}