#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>
#include "kegiatan1.h"
#include "kegiatan2.h"

int main(void){

    int menu;

    up:

    header();
    printf("[?] Pilih kegiatan 1 atau 2 : "); scanf("%d", &menu);

    system("cls");

    switch(menu){
        case 1:
            kegiatan1();
            break;
        case 2:
            kegiatan2();
            break;
    }

    system("cls");
    goto up;
}
