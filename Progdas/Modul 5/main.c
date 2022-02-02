#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Data {

    char name[125];
    char nim[4];
    char clas[2];
    char dosen[125];
    int delet;

};

struct Data User[100];

int length = 0;

void header(void){
    printf("========================\n");
    printf("    APLIKASI INFOKOM\n");
    printf("========================\n");
}

int cekDouble(char n[]){

    int cek = 0;

    for(int i = 0; i < length; i++){
        if(strcmp(User[i].nim, n) == 0){
            cek = 1;
        }
    }

    return cek;
}

int cekActive(int i){

    return (User[i].delet == 1) ?  1 :  0;
}

int getIndex(char n[]){

    for(int i = 0; i < length; i++){
        if(strcmp(User[i].nim, n) == 0){
            return i;
        }
    }

    return -1;}

void creat(char n[], int length, int sts){

    top:

    if(cekDouble(n) == 0 || length < 1 || sts == 1){
        strcpy(User[length].nim, n);
        fflush(stdin);
        printf("[+] Nama Lengkap : "); scanf("%[^\n]s", User[length].name);
        fflush(stdin);
        printf("[+] Kelas        : "); scanf("%[^\n]s", User[length].clas);
        fflush(stdin);
        printf("[+] Nama Dosen   : "); scanf("%[^\n]s", User[length].dosen);

        User[length].delet = 1;

        printf("========================\n");
        printf("[V] Berhasil memperbarui database.\n");
        printf("========================\n");
        fflush(stdin);
        printf("klik enter untuk kembali ke menu..."); getchar();
    }else {
        printf("========================\n");
        fflush(stdin);
        printf("[X] Maaf nim yang anda masukan sudah ada.\nklik enter untuk mengisi ulang form..."); getchar();
        system("cls");

        header();
        printf(" ..:: Tambah User ::..\n");
        printf("========================\n");
        fflush(stdin);
        printf("[+] NIM          : "); scanf("%[^\n]s", n);
        goto top;
    }
}

void edit(char n[]){
    int length = getIndex(n);

    if(length == -1 || User[length].delet == 0){
        printf("[X] User dengan nim IF2021-%s tidak ditemukan.\n", n);
        printf("========================\n");
        fflush(stdin);
        printf("Klik enter untuk kembali ke menu..."); getchar();
    }else {
        creat(n, length, 1);
    }
}

void delet(char n[]){
    int length = getIndex(n);

    if(length == -1 || User[length].delet == 0){
        printf("[X] User dengan nim IF2021-%s tidak ditemukan.\n", n);
        printf("========================\n");
        fflush(stdin);
        printf("Klik enter untuk kembali ke menu..."); getchar();
    }else {
        User[length].delet = 0;
        printf("[V] Berhasil menghapus user dengan nim IF2021-%s\n", n);
        printf("========================\n");
        fflush(stdin);
        printf("Klik enter untuk kembali ke menu..."); getchar();
    }

}

void show(void){

    if(length > 0){
        printf("No\tNama\t\t\tNIM\t\t\tKelas\t\t\tDosen\n");
    }else {
        printf("Belum ada data, silahkan masukan data User.\n");
    }

    for(int i = 0; i < length; i++){
        if(cekActive(i) == 1){
            printf("%d\t%s\t\tIF2021-%s\t\tProgdas %s\t\t%s\n", i+1, User[i].name, User[i].nim, User[i].clas, User[i].dosen);
        }
    }
    printf("========================\n");
    fflush(stdin);
    printf("klik enter untuk kembali ke menu..."); getchar();

}

void search(char n[]){
    int length = getIndex(n);

    fflush(stdin);

    if(length == -1){

        printf("[X] User dengan nim IF2021-%s tidak ditemukan.\n", n);
        printf("========================\n");
        printf("Klik enter untuk kembali ke menu..."); getchar();
    }else {
        printf("[+] NIM          : %s\n", User[length].nim);
        printf("[+] Nama Lengkap : %s\n", User[length].name);
        printf("[+] Kelas        : %s\n", User[length].clas);
        printf("[+] Nama Dosen   : %s\n", User[length].dosen);
        printf("========================\n");
        printf("Klik enter untuk kembali ke menu..."); getchar();
    }
}


int main(){

    int menu;
    char nim[3];

    top:

    header();
    printf("    ..:: MENU ::..\n");
    printf("========================\n");
    printf("1. Tambah User\n");
    printf("2. Edit User\n");
    printf("3. Hapus User\n");
    printf("4. Tampilkan User\n");
    printf("5. Cari User\n");
    printf("6. Exit\n");
    printf("========================\n");
    printf("[~] Pilih Menu : "); scanf("%d", &menu);

    system("cls");
    header();

    switch(menu){
        case 1:
            printf(" ..:: Tambah User ::..\n");
            printf("========================\n");
            fflush(stdin);
            printf("[+] NIM          : IF2021-"); scanf("%[^\n]s", nim);
            creat(nim, length, 0);
            ++length;
            break;
        case 2:
            printf("  ..:: Edit User ::..\n");
            printf("========================\n");
            fflush(stdin);
            printf("[?] NIM          : IF2021-"); scanf("%[^\n]s", nim);
            printf("========================\n");
            edit(nim);
            break;
        case 3:
            printf(" ..:: Hapus User ::..\n");
            printf("========================\n");
            fflush(stdin);
            printf("[?] NIM          : IF2021-"); scanf("%[^\n]s", nim);
            printf("========================\n");
            delet(nim);
            break;
        case 4:
            printf("..:: Tampilkan User ::..\n");
            printf("========================\n");
            show();
            break;
        case 5:
            printf(" ..:: Cari User ::..\n");
            printf("========================\n");
            fflush(stdin);
            printf("[?] NIM          : IF2021-"); scanf("%[^\n]s", nim);
            printf("========================\n");
            search(nim);
            break;

        default:
            printf("Berhasil mengakhiri program...\n");
            printf("========================\n");
            return 0;
            break;
    }

    system("cls");
    goto top;
}
