#include <stdio.h>
#include <math.h>

float looping(int n){

    float hitung, rumus;

    for(int i = 1; i <= n; i++){
        hitung += 1 / pow(i,2);
    }

    rumus = 6 * hitung;
    return sqrt(rumus);
}

int main() {
    printf("+---------------+\n");
    printf("|n\tf(n)\t|\n");
    printf("+---------------+\n");

    for(int i = 2; i <= 20; i+=2){
        printf("|%d\t%.5f |\n", i, looping(i));
    }
    printf("+---------------+");
}
