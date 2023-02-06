#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int outRow=0,outCol=0;
int states,variables;
char state[10][10];
char variable[10][10];
char outputTable[20][10][1000]={'\0'};
char inputTable[10][10][1000];
char outputStates[20][200];
int it=0;
int outputStatesChecker(char state[]){
    for(int i=0;i<it;i++){
        if(strcmp(state,outputStates[i])==0){
            return 1;
        }
    }
    return 0;
}
int  compositeChecker(char state[]){
    int len=strlen(state);
    if(len>=4){
        return 1;
    }
    return 0;
}
void splitterAndAdder(char state[]){
    int splitar[20],k=0;
    for(int i=1;i<strlen(state);i+=2){
        splitar[k]=state[i]-'0';k++;
    }
    for(int i=0;i<variables;i++){
        char tempAr[100];
        bzero(tempAr,100);
        for(int j=0;j<k;j++){
            if(strcmp(inputTable[splitar[j]-1][i],"*")==0){
                continue;
            }
            strcat(tempAr,inputTable[splitar[j]-1][i]);
        }
        strcpy(outputTable[outRow][i],tempAr);
    }
    outRow++;
}
void displayOutput(){
    int m=0,k=0;
    printf("\n\nOutput Table\n\n");
    printf("\t");
    for(int i=0;i<variables;i++){
        printf("%c    ",'a'+k);
        k++;
    }
    printf("\n");
    for(int i=0;i<outRow;i++){
        printf("\n%s\t",outputStates[m]);
        m++;
        for(int j=0;j<variables;j++){
            printf("%s  ",outputTable[i][j]);
        }
        printf("\n");
    }
}
void displayInput(){
    int m=1,k=0;
    printf("\n\nInput Table\n\n");
    printf("\t");
    for(int i=0;i<variables;i++){
        printf("%c    ",'a'+k);
        k++;
    }
    printf("\n");
    for(int i=0;i<states;i++){
        printf("\n%s%d\t","q",m);
        m++;
        for(int j=0;j<variables;j++){
            if( (strcmp(inputTable[i][j],"*"))==0  ){
                printf("%s    ",inputTable[i][j]);
            }
            else{
                printf("%s  ",inputTable[i][j]);
            }
        }
        printf("\n");
    }
}
void main(){
    printf("\nEnter the number of states and states : ");
    scanf("%d",&states);
    for(int i=0;i<states;i++)
    scanf("%s",state[i]);
    printf("Enter the number of variables and variables : ");
    scanf("%d",&variables);
    for(int i=0;i<variables;i++)
    scanf("%s",variable[i]);
    printf("Enter the Table values\n");
    for(int i=0;i<states;i++){
        for(int j=0;j<variables;j++){
            scanf("%s",inputTable[i][j]);
        }
    }
    displayInput();
    for(int j=0;j<variables;j++)
    strcpy(outputTable[0][j],inputTable[0][j]);
    outRow++;
    strcpy(outputStates[it],"q1");
    it++;
    for(int row=0;row<states*2;row++){
        for(int col=0;col<variables;col++){
            if(outputTable[row][col][0]=='\0'){
                displayOutput();
                exit(0);
            }
            char tempStr[50];
            strcpy(tempStr,outputTable[row][col]);
            int val = outputStatesChecker(tempStr);
            if(val==0){
                strcpy(outputStates[it],tempStr);
                it++;
                int retval = compositeChecker(tempStr);
                if(retval==0){
                    int index=tempStr[1]-'0';
                    for(int m=0;m<variables;m++){
                        strcpy(outputTable[outRow][m],inputTable[index][m]);
                    }
                    outRow++;
                }
                else{
                    splitterAndAdder(tempStr);
                }
            }
        }
    }
}