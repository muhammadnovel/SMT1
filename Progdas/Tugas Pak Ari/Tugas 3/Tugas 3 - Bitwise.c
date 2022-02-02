#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    long int a, b;
    char op;

    up:
    printf("Masukan nilai A : "); scanf("%li", &a);
    fflush(stdin);
    printf("Masukan nilai B : "); scanf("%li", &b);
    fflush(stdin);
    printf("Masukan Operator Bitwise [|,&,^,~,<<,>>]: "); scanf("%c", &op);

    switch(op){

        case '|':
            printf("[~] A | B adalah %li\n", a|b);
            break;
        case '&':
            printf("[~] A & B adalah %li\n", a&b);
            break;
        case '^':
            printf("[~] A ^ B adalah %li\n", a^b);
            break;
        case '~':
            printf("[~] ~A adalah %li\n", ~a);
            break;
        case '<':
            printf("[~] A << 3 adalah %li\n", a<<3);
            break;
        case '>':
            printf("[~] A >> 3 adalah %li\n", a>>3);
            break;
    }

    fflush(stdin);
    printf("Tekan enter untuk melanjutkan program");getchar();
    system("cls");
    goto up;
}

