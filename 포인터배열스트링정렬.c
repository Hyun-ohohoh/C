#include <stdio.h>
#include <string.h>
int main(){
    char str [20][99];
    char *ptr[20];
    int num = 0;
    while(num < 20 && scanf("%s", str[num]) != EOF){
        num++;
    }
    for(int i = 0; i < num; i++){
        ptr[i] = str[i];
    }
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num-1-i; j++){
            if(strcmp(ptr[j], ptr[j+1]) > 0){
                char * temp;
                temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }     
        }
    }
    printf("정렬 후\n");
    for(int i = 0; i < num; i++){
        printf("%s\n", ptr[i]);
    }   
    printf("정렬 전\n");
    for(int i = 0; i < num; i++){
        printf("%s\n", str[i]);
    }
    return 0;
}