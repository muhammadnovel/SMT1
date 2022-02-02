#include <stdio.h>

void bintang(int n){

    for(int i = 0; i < n; i++){
        printf("*");
    }
}

int main(void){

    for(int i = 1; i <= 21; i++){
        if(i % 2 == 0){
            bintang(i);
        }else{
            printf("%d", i);
        }
        printf("\n");
    }
}
