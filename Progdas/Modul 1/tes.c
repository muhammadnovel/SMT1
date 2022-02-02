#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ascii()
{
    printf("\n\n");
    printf(" /$$$$$$$                   /$$        /$$     /$$ /$$             /$$      /$$                 /$$           /$$         /$$\n");
    printf("| $$__  $$                 | $$       | $$    |__/| $$            | $$$    /$$$                | $$          | $$       /$$$$\n");
    printf("| $$  \\ $$/$$$$$$  /$$$$$$ | $$   /$$/$$$$$$   /$$| $$   /$$      | $$$$  /$$$$  /$$$$$$   /$$$$$$$ /$$   /$$| $$      |_  $$\n");
    printf("| $$$$$$$/$$__  $$|____  $$| $$  /$$/_  $$_/  | $$| $$  /$$/      | $$ $$/$$ $$ /$$__  $$ /$$__  $$| $$  | $$| $$        | $$\n");
    printf("| $$____/ $$  \\__/ /$$$$$$$| $$$$$$/  | $$    | $$| $$$$$$/       | $$  $$$| $$| $$  \\ $$| $$  | $$| $$  | $$| $$        | $$\n");
    printf("| $$    | $$      /$$__  $$| $$_  $$  | $$ /$$| $$| $$_  $$       | $$\\  $ | $$| $$  | $$| $$  | $$| $$  | $$| $$        | $$\n");
    printf("| $$    | $$     |  $$$$$$$| $$ \\  $$ |  $$$$/| $$| $$ \\  $$      | $$ \\/  | $$|  $$$$$$/|  $$$$$$$|  $$$$$$/| $$       /$$$$$$\n");
    printf("|__/    |__/      \\_______/|__/  \\__/  \\___/  |__/|__/  \\__/      |__/     |__/ \\______/  \\_______/ \\______/ |__/      |______/\n");
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("[*] Program Penghitung Nilai Rata-Rata\n");
    printf("[*] Nama    : Muhammad Novel\n");
    printf("[*] NIM     : 202110370311320\n");
    printf("[*] Kelas   : Informatika G\n");
    printf("------------------------------------------------------------\n\n");
}

int main()
{
    SetConsoleTitle("Program Penghitung Nilai Rata-Rata");
    int menu, edit;
    float pd, k, p, o, rata;
    ascii();
    printf("Silahkan masukan Nilai Pemrograman Dasar, Nilai Kalkulus, Nilai Orkom, Nilai PTI : ");
    scanf("%f  %f  %f  %f", &pd, &k, &p, &o);
    system("cls");
    do
    {
        ascii();
        printf("Apakah anda yakin nilai yang anda masukan sudah benar?\n\n");
        printf("[-] Nilai Pemrograman Dasar : %.1f\n", pd);
        printf("[-] Nilai Kalkulus          : %.1f\n", k);
        printf("[-] Nilai Orkom             : %.1f\n", o);
        printf("[-] Nilai PTI               : %.1f\n\n", p);
        printf("Silahkan pilih menu dibawah ini :\n\n");
        printf("[1.] Melihat status kelulusan \n");
        printf("[2.] Merubah nilai \n");
        printf("[3.] Exit \n\n");
        printf("Pilih menu : ");
        scanf("%d", &menu);
        printf("\n");
        switch (menu)
        {
        case 1:
            rata = (pd + k + o + p) / 4;
            if (rata >= 75)
            {
                printf("Selamat anda dinyatakan LULUS dengan nilai rata rata : %.1f \n\n", rata);
            }
            else
            {
                printf("Maaf anda dinyatakan TIDAK LULUS dengan rata rata : %.1f \n\n", rata);
            }
            return 0;
            break;
        case 2:
            system("cls");
            ascii();
            printf("Silahkan pilih mata kuliah mana yang ingin anda rubah :\n\n");
            printf("[1.] Pemrograman Dasar\n");
            printf("[2.] Kalkulus\n");
            printf("[3.] Orkom\n");
            printf("[4.] PTI\n\n");
            printf("Pilih mata kuliah : ");
            scanf("%d", &edit);
            switch (edit)
            {
            case 1:
                printf("Silahkan masukan Nilai Pemrograman Dasar : ");
                scanf("%f", &pd);
                break;
            case 2:
                printf("Silahkan masukan Nilai Kalkulus : ");
                scanf("%f", &k);
                break;
            case 3:
                printf("Silahkan masukan Nilai Orkom : ");
                scanf("%f", &o);
                break;
            case 4:
                printf("Silahkan masukan Nilai PTI : ");
                scanf("%f", &p);
                break;
            }
            system("cls");
            break;
        case 3:
            return 0;
            break;
        }
    } while (menu < 4 && menu > 0 && edit < 5 && edit > 0);
}
