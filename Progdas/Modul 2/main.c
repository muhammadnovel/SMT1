#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

#include "rumus.h"
#include "caption.h"

void menus(char name[100]) {
    printf("Hai %s, ini adalah demo dari aplikasi modul 2\n", name);
    printf("fungsi dibuat aplikasi ini adalah untuk membantu menghitung volume dan luas permukaan bangun ruang.\n\n");
    printf("Silahkan Pilih Menu Dibawah Ini :\n\n");
    printf("[*] Menu Luas\n\n");
    printf("[1] Menghitung Luas Permukaan Balok\n");
    printf("[2] Menghitung Luas Permukaan Kubus\n");
    printf("[3] Menghitung Luas Permukaan Tabung\n");
    printf("[4] Menghitung Luas Permukaan Kerucut\n\n");
    printf("[*] Menu Volume\n\n");
    printf("[5] Menghitung Volume Balok\n");
    printf("[6] Menghitung Volume Kubus\n");
    printf("[7] Menghitung Volume Tabung\n");
    printf("[8] Menghitung Volume Kerucut\n\n");
    printf("[9] Shutdown Computer\n");
    printf("[0] Keluar\n\n");
}

void header(void) {
    printf("\t ____            _    _   _ _      __  __           _       _   ____ \n");
    printf("\t|  _ \\ _ __ __ _| | _| |_(_) | __ |  \\/  | ___   __| |_   _| | |___ \\\n");
    printf("\t| |_) | '__/ _` | |/ / __| | |/ / | |\\/| |/ _ \\ / _` | | | | |   __) |\n");
    printf("\t|  __/| | | (_| |   <| |_| |   <  | |  | | (_) | (_| | |_| | |  / __/\n");
    printf("\t|_|   |_|  \\__,_|_|\\_\\\\__|_|_|\\_\\ |_|  |_|\\___/ \\__,_|\\__,_|_| |_____|\n\n");
    printf("=======================================================================================\n\n");
    printf("    [+] Menghitung Luas Permukaan & Volume Bagngun Ruang Menggunakan Function [+]\n\n");
    printf("=======================================================================================\n");
    printf("[+] Nama\t: Muhammad Novel\n");
    printf("[+] NIM\t\t: 202110370311320\n");
    printf("[+] Kelas\t: Informatika G\n");
    printf("[+] Asisten Lab\t: Muhammad Zulfiqor Lilhaq\n");
    printf("=======================================================================================\n");
}

void footer(void) {
    system("cls");
    printf("\t _____         _                   _  __         _ _\n");
    printf("\t|_   _|__ _ __(_)_ __ ___   __ _  | |/ /__ _ ___(_) |__\n");
    printf("\t  | |/ _ \\ '__| | '_ ` _ \\ / _` | | ' // _` / __| | '_ \\\n");
    printf("\t  | |  __/ |  | | | | | | | (_| | | . \\ (_| \\__ \\ | | | |\n");
    printf("\t  |_|\\___|_|  |_|_| |_| |_|\\__,_| |_|\\_\\__,_|___/_|_| |_|\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                       [+] Code By Muhammad Novel [+]\n");
    printf("---------------------------------------------------------------------------\n\n");
}

int main(void) {
    SetConsoleTitle("Program Menghitung Luas & Volume Bangun Ruang");
    int menu;
    char ext, name[100];
    header();

    printf("Silahkan masukan nama kamu : ");
    scanf("%[^\n]s", name);
    system("cls");

    header();
    do {

        if (ext == 'y') {
            footer();
            exit(0);
        }
        menus(name);
        printf("Pilih menu : ");
        scanf("%d", & menu);
        system("cls");
        header();
        switch (menu) {
        case 1:
            cl_balok();
            break;
        case 2:
            cl_kubus();
            break;
        case 3:
            cl_tabung();
            break;
        case 4:
            cl_kerucut();
            break;
        case 5:
            cv_balok();
            break;
        case 6:
            cv_kubus();
            break;
        case 7:
            cv_tabung();
            break;
        case 8:
            cv_kerucut();
            break;
        case 9:
            system("shutdown /s /t 6");
            for (int c = 5; c > 0; c--) {
                system("cls");
                footer();
                printf("Komputer akan dimatikan dalam %i detik...\n\n", c);
                sleep(1);
            }
            exit(0);
            break;
        case 0:
            footer();
            exit(0);
            break;
        default:
            printf("[!] Menu tidak diketahui, silahkan pilih menu yang ada!\n");
            printf("=======================================================================================\n");
            break;
        }

        if (menu < 9) {
            printf("=======================================================================================\n");
            printf("Apakah anda ingin menutup program ? (y/n) : ");
            scanf("%s", &ext);
            system("cls");
            header();
        }
    } while (1);
}


