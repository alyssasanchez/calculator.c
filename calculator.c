#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM_DIGITS 255

int isInteger(char* valString){
   if (!strcmp(valString,"0")) return 1;
   if (atoi(valString)==0) return 0;
   return 1;
}
int main(){
        arrayStack_t stack;
        initStack(&stack, 10);
        char character[MAX_NUM_DIGITS];
        printf("Calculator Input:");
        scanf("%s", character);
        while(character[0]!='q'){
                if(isInteger(character)==1){
                        push(&stack, atoi(character));
                }
                else if (character [0]=='+'|| character[0]=='-'|| character[0]=='*' || character[0]=='/'){
                        int numbers1,numbers2;
                        if (pop(&stack,&numbers1)==0){
                                printf("Empty Stack\n");
                        }
                        else if(pop(&stack, &numbers2)==0){
                                printf("Not enough arguments\n");
                                push(&stack, numbers1);
                        }
                        else if(character[0]=='+'){
                                push(&stack,numbers2+numbers1);
                                printf("%d\n", numbers2+numbers1);
                        }
                        else if(character[0]=='-'){
                                push(&stack,numbers1-numbers2);
                                printf("%d\n",numbers1-numbers2);
                        }

                        else if(character[0]=='*'){
                                push(&stack,numbers2*numbers1);
                                printf("%d\n",numbers2*numbers1);
                        }
                        else if(character[0]=='/'){
                                if(numbers2==0){
                                        printf("ERROR:Division by 0\n");
                                        int value;
                                        while(pop(&stack,&value)){
                                                continue;
                                        }
                                }
                                else{
                                        push(&stack,numbers1/numbers2);
                                        printf("%d\n", numbers1/numbers2);
                                }
                        }
                }
                else{
                        printf("ERROR: Invalid Input\n");
                }
                scanf("%s", character);
        }
                                                                                                                                                                                          1,1           Top
