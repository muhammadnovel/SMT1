#include <stdio.h>
#include <stdlib.h>

void main(void){
    float a,b,c;

    up:
    printf("Masukan nilai A : "); scanf("%f", &a);
    fflush(stdin);
    printf("Masukan nilai B : "); scanf("%f", &b);
    fflush(stdin);
    printf("Masukan nilai C : "); scanf("%f", &c);

    printf("-----------------------------\n");

    printf("1. (%.1f + %.1f) x %.1f + %.1f + %.1f + (%.1f / %.1f + %.1f) = %.2f\n", a, b, c, a, b, b, a, c, (a + b) * c + a + b + ( b / a + c));

    fflush(stdin);
    printf("Tekan enter untuk melanjutkan program");getchar();
    system("cls");
    goto up;

}
