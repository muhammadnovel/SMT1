#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>

struct Menu {
    char m[100];
    int h, p, t;
};

struct Menu pesen[];
char pilih[100], k;
int status, harga, n;

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

void decalration(void) {
    strcpy(pesen[0].m, "Aceh\t");
    pesen[0].h = 5000;

    strcpy(pesen[1].m, "Soto Mie");
    pesen[1].h = 5000;

    strcpy(pesen[2].m, "Cabe Ijo");
    pesen[2].h = 5000;

    strcpy(pesen[3].m, "Goreng\t");
    pesen[3].h = 5000;

    strcpy(pesen[4].m, "Sambal Matah");
    pesen[4].h = 5500;

    strcpy(pesen[5].m, "Rendang\t");
    pesen[5].h = 5000;

    strcpy(pesen[6].m, "Iga Penyet");
    pesen[6].h = 5000;

    strcpy(pesen[7].m, "Es Teh\t");
    pesen[7].h = 4500;

    strcpy(pesen[8].m, "Teh Panas");
    pesen[8].h = 4000;

    strcpy(pesen[9].m, "Es Jeruk");
    pesen[9].h = 4500;

    strcpy(pesen[10].m, "Jeruk Panas");
    pesen[10].h = 4000;

    strcpy(pesen[11].m, "Es Degan");
    pesen[11].h = 8000;
}

void reset(void) {

    system("cls");
}

void header() {
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

}

void menus(void) {
    printf("\t\tDAFTAR MENU\n");
    printf("\t    WARUNG MAKAN INDOMIE\n\n");
    printf("---------------------------------------------------\n");
    printf("No.\tMakanan\t\t\tHarga\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("%i.\t%s\t\tRp.%i,-\n", i + 1, pesen[i].m, pesen[i].h);
    }

    printf("---------------------------------------------------\n");
    printf("No.\tMinuman\t\t\tHarga\n");
    printf("---------------------------------------------------\n");

    for (int i = 7; i < 12; i++) {
        printf("%i.\t%s\t\tRp.%i,-\n", i + 1, pesen[i].m, pesen[i].h);
    }
    printf("---------------------------------------------------\n");
}

int main(void) {
    SetConsoleTitle("WARMINDO");
    int loop = 0, y;
    decalration();

    SetColor(10);
    header();
    printf("Klik enter untuk memulai program...");  getchar();
    reset();

    do {
        up:
        SetColor(11);
        menus();

        SetColor(15);
        printf("[~] Silahkan pilih pesanan anda : ");
        scanf("%s", pilih);

        reset();

        SetColor(11);
        printf("====================================\n");

        SetColor(14);
        char * token = strtok(pilih, ",");
        while (token != NULL) {

            y = atoi(token) - 1;

            if(y < 12){
                pesen[loop].p = y;
                printf("[+] Jumlah pesanan %s\b\t: ", pesen[y].m);
                scanf("%i", &pesen[loop].t);
                loop++;
            }else {
                printf("[+] Menu dengan Id %d tidak ada\n", y+1);
            }

            token = strtok(NULL, ",");
        }

        SetColor(11);
        printf("====================================\n");
        printf("1. Bayar\n");
        printf("2. Tambah pesanan\n");
        printf("====================================\n");
        SetColor(15);
        printf("[~] Pilih menu : ");
        scanf("%d", &status);

        switch (status) {
        case 1:
           up2:
            reset();
            SetColor(11);

            printf("\t\t\t-- NOTA PEMBAYARAN --\n");
            printf("\t\t\tWARUNG MAKAN INDOMIE\n\n");
            printf("--------------------------------------------------------------------\n");
            printf("No.\tJenis\t\t\tQty\t\tHarga\n");
            printf("--------------------------------------------------------------------\n");

            for(int i = 0; i < loop; i++){
                printf("%i.\t%s\t\t\%i\t\tRp.%i,-\n", i+1, pesen[pesen[i].p].m, pesen[i].t, pesen[pesen[i].p].h * pesen[i].t);
                harga += pesen[pesen[i].p].h * pesen[i].t;
            }

            printf("--------------------------------------------------------------------\n");
            printf("Grand Total\t\t\t\t\tRp.%i,-\n",  harga);

            if(n != 0 && n >= harga){
                printf("Tunai\t\t\t\t\t\tRp.%i,-\n",  n);
                printf("Kembalian\t\t\t\t\tRp.%i,-\n", n - harga);
                printf("--------------------------------------------------------------------\n");
            }else if(n < harga && n != 0){
                printf("Tunai\t\t\t\t\t\tRp.%i,-\n",  n);
                SetColor(4);
                printf("Kurang\t\t\t\t\t\tRp.%i,-\n", harga - n);
                SetColor(11);
                printf("--------------------------------------------------------------------\n");
                SetColor(4);
                printf("Maaf uang anda kurang!\n\n");
                SetColor(15);
                printf("[~] Nominal Pembayaran : "); scanf("%d", &n);
                reset();
                harga = 0;
                goto up2;
            }else {
                printf("--------------------------------------------------------------------\n");
                SetColor(15);
                printf("[~] Nominal Pembayaran : ");
                scanf("%d", &n);
                reset();
                harga = 0;
                goto up2;
            }

            break;

        case 2:
            reset();
            goto up;
            break;
        default:
            SetColor(4);
            reset();
            for(int i = 1; i < 6; i++){
                reset();
                printf("Menu tidak ditemukan, anda akan diarahkan ke halaman menu  dalam %d...", i);
                Sleep(1000);
            }
            reset();
            goto up;
        }

        SetColor(15);
        printf("Apakah anda ingin mengakhiri program ? [Y/N] : "); scanf("%s", &k);

        switch(k){

        case 'Y':
        case 'y':
            return 0;
            break;
        case 'N':
        case 'n':
            status = harga = n = loop = 0;
            reset();
            break;
        }

    } while (1);
}

