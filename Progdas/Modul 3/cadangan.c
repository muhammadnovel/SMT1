#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Soal {
    char pertanyaan[500], a[500], b[500], c[500], d[500], kunci[2];
};

struct Jawab{
    char simpan[2];
};

struct Soal dekdata[5];
struct Jawab datajawab[5];
char nama[20], kelas[20], absent[20], a, b;
int nilai = 100;

void createSoal(void){

    strcpy(dekdata[0].pertanyaan, "Hasil dari 15 x 50 / 30 adalah....");
    strcpy(dekdata[0].a, "25");
    strcpy(dekdata[0].b, "35");
    strcpy(dekdata[0].c, "45");
    strcpy(dekdata[0].d, "55");
    strcpy(dekdata[0].kunci, "a");

    strcpy(dekdata[1].pertanyaan, "Hasil dari 172 - 152 adalah....");
    strcpy(dekdata[1].a, "4");
    strcpy(dekdata[1].b, "16");
    strcpy(dekdata[1].c, "64");
    strcpy(dekdata[1].d, "128");
    strcpy(dekdata[1].kunci, "c");

    strcpy(dekdata[2].pertanyaan, "Hasil dari 70 - (-25) adalah....");
    strcpy(dekdata[2].a, "–95 ");
    strcpy(dekdata[2].b, "–45");
    strcpy(dekdata[2].c, "45");
    strcpy(dekdata[2].d, "95");
    strcpy(dekdata[2].kunci, "d");

    strcpy(dekdata[3].pertanyaan, "FPB dari 48, 72 dan 96 adalah....");
    strcpy(dekdata[3].a, "2^5 x 3");
    strcpy(dekdata[3].b, "2^4 x 3");
    strcpy(dekdata[3].c, "2^3 x 3");
    strcpy(dekdata[3].d, "2^2 x 3");
    strcpy(dekdata[3].kunci, "c");

    strcpy(dekdata[4].pertanyaan, "Kebun Pak Warno berbentuk persegi panjang dengan ukuran panjang 4,2 dam dan lebar 370 dm. Keliling kebun Pak Warno adalah...meter");
    strcpy(dekdata[4].a, "82,4");
    strcpy(dekdata[4].b, "124");
    strcpy(dekdata[4].c, "158");
    strcpy(dekdata[4].d, "225");
    strcpy(dekdata[4].kunci, "c");
}

void header(void) {

    printf(" _______  _______  _______     ___ ___  _____ \n");
    printf("|   _   ||   _   \\|       |   |   Y   || _   |\n");
    printf("|.  1___||.  1   /|.|   | |   |.  |   ||.|   |\n");
    printf("|.  |___ |.  _   \\`-|.  |-'   |.  |   |`-|.  |\n");
    printf("|:  1   ||:  1    \\ |:  |     |:  1   |  |:  |\n");
    printf("|::.. . ||::.. .  / |::.|      \\:.. ./   |::.|\n");
    printf("`-------'`-------'  `---'       `---'    `---'\n");
    printf("=================================================\n");
    printf("Mata Pelajaran\t: Matematika\n");
    printf("Nama\t\t: %s\n", nama);
    printf("Kelas\t\t: %s\n", kelas);
    printf("Absent\t\t: %s\n", absent);
    printf("=================================================\n");

}

int main(void) {

    createSoal();
    header();

    printf("Masukan Nama : "); scanf("%[^\n]s", nama); getchar();
    printf("Masukan Kelas : "); scanf("%[^\n]s", kelas); getchar();
    printf("Masukan Absent : "); scanf("%[^\n]s", absent); getchar();

    system("cls");

    for (int i = 0; i < 5; i++) {
        header();
        printf("%i. %s\n\n", i + 1, dekdata[i].pertanyaan);
        printf("A. %s\t\t", dekdata[i].a);
        printf("C. %s\n", dekdata[i].c);
        printf("B. %s\t\t", dekdata[i].b);
        printf("D. %s\n\n", dekdata[i].d);
        printf("[-] Jawab : "); scanf("%s", datajawab[i].simpan);


        if(strcmp(datajawab[i].simpan, dekdata[i].kunci)){
            nilai -= 20;
        }

        system("cls");
    }

    header();
    printf("[+] Jawaban Anda : \n\n");
    for (int i = 0; i < 5; i++){
        printf("%i. %s\n", i+1, datajawab[i].simpan);
    }

    printf("\n[+] Nilai Anda : %i", nilai);

    return 0;
}
