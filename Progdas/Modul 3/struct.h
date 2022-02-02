#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>

#define ppn 0.10

struct Data {
    char jenis[100], space[100];
    int harga;
};

struct Data2 {
    int pesan, total, toppingHarga;
    char toping[100];
};

struct Data menu[] = {
    {"Indomie Aceh","          ", 5000},
    {"Indomie Soto Mie","      ", 6000},
    {"Indomie Cabe Ijo","      ", 5000},
    {"Indomie Goreng","        ", 5000},
    {"Indomie Sambal Matah","  ", 5000},
    {"Indomie Rendang","       ", 5000},
    {"Indomie Iga Penyet","    ", 5000},
    {"Es Teh","                ", 3500},
    {"Teh Panas","             ", 3000},
    {"Es Jeruk","              ", 4500},
    {"Jeruk Panas","           ", 4000},
    {"Es Degan","              ", 8000},
    {"Telur","                 ", 4500},
    {"Kornet","                ", 6000},
    {"Keju","                  ", 5500},
    {"Bakso","                 ", 5500},
    {"Sosis","                 ", 5500},
    {"Daging Asap","           ", 5500},
    {"Ati AMpela","            ", 8000},
    {"Mozzarella","            ", 10000},
    {"Saus Telur Asin","       ", 10000},
    {"Tanpa Toping","          ", 0}
};

struct Data2 nota[10000];

void SetColor(int ForgC) {
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void header() {
    char pass[20], user[20];

    printf(" /$$      /$$  /$$$$$$  /$$$$$$$  /$$      /$$ /$$$$$$ /$$   /$$ /$$$$$$$   /$$$$$$\n");
    printf("| $$  /$ | $$ /$$__  $$| $$__  $$| $$$    /$$$|_  $$_/| $$$ | $$| $$__  $$ /$$__  $$\n");
    printf("| $$ /$$$| $$| $$  \\ $$| $$  \\ $$| $$$$  /$$$$  | $$  | $$$$| $$| $$  \\ $$| $$  \\ $$\n");
    printf("| $$/$$ $$ $$| $$$$$$$$| $$$$$$$/| $$ $$/$$ $$  | $$  | $$ $$ $$| $$  | $$| $$  | $$\n");
    printf("| $$$$_  $$$$| $$__  $$| $$__  $$| $$  $$$| $$  | $$  | $$  $$$$| $$  | $$| $$  | $$\n");
    printf("| $$$/ \\  $$$| $$  | $$| $$  \\ $$| $$\\  $ | $$  | $$  | $$\\  $$$| $$  | $$| $$  | $$\n");
    printf("| $$/   \\  $$| $$  | $$| $$  | $$| $$ \\/  | $$ /$$$$$$| $$ \\  $$| $$$$$$$/|  $$$$$$/\n");
    printf("|__/     \\__/|__/  |__/|__/  |__/|__/     |__/|______/|__/  \\__/|_______/  \\______/\n");
    printf("===================================================================================================\n");
    printf("[-] Judul\t: Warung Makan Indomie\n[-] Nama\t: Muhammad Novel\n[-] Kelas\t: Informatika G\n[-] NIM\t\t: 202110370311320\n[-] Aslab\t: Syahrul\n");
    printf("===================================================================================================\n");
    wp:
    printf("Masukan Username : "); scanf("%s", user);
    fflush(stdin);
    printf("Masukan Password : "); scanf("%s", pass);

    if(strcmp(user, "novel") != 0 || strcmp(pass, "320") != 0){
        printf("===================================================================================================\n");
        SetColor(4);
        printf("Username atau password salah!\n");
        SetColor(10);
        printf("===================================================================================================\n");
        goto wp;
    }
}

void menus(void) {
    printf("\t\tDAFTAR MENU\n");
    printf("\t    WARUNG MAKAN INDOMIE\n\n");
    printf("---------------------------------------------------\n");
    printf("No.\tMakanan\t\t\tHarga\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("%i.\t%s%s\tRp.%i,-\n", i + 1, menu[i].jenis, menu[i].space, menu[i].harga);
    }

    printf("---------------------------------------------------\n");
    printf("No.\tMinuman\t\t\tHarga\n");
    printf("---------------------------------------------------\n");

    for (int i = 7; i < 12; i++) {
        printf("%i.\t%s%s\tRp.%i,-\n", i + 1, menu[i].jenis, menu[i].space, menu[i].harga);
    }

    printf("---------------------------------------------------\n");
}

void toping(void) {
    printf("\t\tDAFTAR MENU\n");
    printf("\t    WARUNG MAKAN INDOMIE\n\n");
    printf("---------------------------------------------------\n");
    printf("No.\tTopping\t\t\tHarga\n");
    printf("---------------------------------------------------\n");

    for (int i = 12; i < 22; i++) {
        printf("%i.\t%s%s\tRp.%i,-\n", i + 1, menu[i].jenis, menu[i].space, menu[i].harga);
    }

    printf("---------------------------------------------------\n");
}

void addTopping(char topping[100], int loop) {
    int split2;
    char * tp = strtok(topping, ",");
    while (tp != NULL) {

        split2 = atoi(tp) - 1;

        if (split2 > 11) {
            strcat(nota[loop].toping, menu[split2].jenis);
            strcat(nota[loop].toping, ", ");
            nota[loop].toppingHarga += menu[split2].harga;
        }

        tp = strtok(NULL, ",");
    }
}

void reset(void) {
    system("cls");
}

char pilih[100], topping[100], konfirmasi;
int status, harga = 0, bayar = 0, loop = 0, split;
float pajak, grandTotal;
