#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bitwise(void){
    long int a, b;
    char op;

    nt:
    printf("Masukan nilai A : "); scanf("%li", &a);
    fflush(stdin);
    printf("Masukan nilai B : "); scanf("%li", &b);
    fflush(stdin);
    printf("Masukan Operator Bitwise [|,&,^,~,<<,>>]: "); scanf("%c", &op);
    printf("\n");
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
        default:
            printf("Operator tidak ditemukan !\n");
            fflush(stdin);
            printf("==============================================\n");
            printf("Tekan enter untuk melanjutkan program"); getchar();
            system("cls");
            goto nt;
    }
}

void unary(void){
    long int a;
    long int *b;
    char op[3];

    nt:
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
    } else {
        printf("Operator tidak ditemukan!\n");
        fflush(stdin);
        printf("==============================================\n");
        printf("Tekan enter untuk melanjutkan program"); getchar();
        system("cls");
        goto nt;
    }
}

void precedence(void){
    float a,b,c;

    printf("Masukan nilai A : "); scanf("%f", &a);
    printf("Masukan nilai B : "); scanf("%f", &b);
    printf("Masukan nilai C : "); scanf("%f", &c);
    printf("\n");
    printf("1. (%.1f + %.1f) x %.1f + %.1f + %.1f + (%.1f / %.1f + %.1f) = %.2f\n", a, b, c, a, b, b, a, c, (a + b) * c + a + b + ( b / a + c));
}

void main(void){
    int menu;
    up:
    printf("====== TUGAS 3 - OPERATOR PADA BAHASA C ======\n");
    printf("1. Porgram Bitwise\n");
    printf("2. Porgram Unary\n");
    printf("3. Porgram Precedence\n");
    printf("==============================================\n");
    printf("Pilih program : "); scanf("%d", &menu);
    printf("==============================================\n");

    switch(menu){
        case 1:
            bitwise();
            break;
        case 2:
            unary();
            break;
        case 3:
            precedence();
            break;
        default:
            printf("Menu tidak ditemukan !\n");
    }
    printf("==============================================\n");
    fflush(stdin);
    printf("Tekan enter untuk melanjutkan program");getchar();
    system("cls");
    goto up;
}

