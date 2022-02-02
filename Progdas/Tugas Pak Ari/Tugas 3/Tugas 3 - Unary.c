#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void) {
    long int a;
    long int *b;
    char op[3];

    up:
    printf("Masukan Operator Unary [*,&,+,-,!,~,++,--]: ");
    scanf("%s", op);
    fflush(stdin);

    if(strcmp(op, "*") == 0){

        b = (long int *) malloc(15);

        printf("Masukan nilai A : ");
        scanf("%li", b);
        fflush(stdin);

    } else {

        printf("Masukan nilai A : ");
        scanf("%li", &a);
        fflush(stdin);
    }

    if (strcmp(op, "*") == 0) {

        printf("[~] *A adalah %li\n", *b);

    } else if (strcmp(op, "&") == 0) {

        printf("[~] &A adalah %li\n", &a);

    } else if (strcmp(op, "+") == 0) {

        printf("[~] +A adalah %li\n", +a);

    } else if (strcmp(op, "-") == 0) {

        printf("[~] -A adalah %li\n", -a);

    } else if (strcmp(op, "!") == 0) {

        printf("[~] !A adalah %li\n", !a);

    } else if (strcmp(op, "~") == 0) {

        printf("[~] ~A adalah %li\n", ~a);

    } else if (strcmp(op, "++") == 0) {

        printf("[~] ++A adalah %li\n", ++a);

    } else if (strcmp(op, "--") == 0) {

        printf("[~] --A adalah %li\n", --a);
    }

    printf("Tekan enter untuk melanjutkan program");getchar();
    system("cls");
    goto up;
}

