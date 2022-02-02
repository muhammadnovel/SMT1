#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

struct Data
{
    char nim[18];
    char name[100];
    char class[10];
    char dosen[100];
    int status;
};

struct Data user[100];
int length = 0;
int run = 0;

void __header(void);
void __menu(void);
void __notFound(void);
void __add(void);
void __search(void);
void __show(void);
void __pushToFIle(void);
void __pushToStruct(void);
void clean_stdin(void);

int main()
{
    int menu;
    if (run == 0)
    {
        __pushToStruct();
        run = 1;
    }

top:
    __header();
    __menu();
    printf("+================================================================+\n");
    printf("[~] Pilih Menu  : ");
    scanf("%d", &menu);

    system("clear");
    __header();

    switch (menu)
    {
    case 1:
        printf("|                           TAMBAH DATA                          |\n");
        printf("+================================================================+\n");
        __add();
        break;
    case 2:
        printf("|                            Cari Data                           |\n");
        printf("+================================================================+\n");
        __search();
        break;
    case 3:
        printf("|                          Tampilkan Data                        |\n");
        printf("+================================================================+\n");
        __show();
        break;
    case 4:
        printf("[V] Menutup program");
        __pushToFIle();
        exit(0);
        break;

    default:
        __notFound();
        break;
    }

    goto top;
}

void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void __header(void)
{

    system("clear");
    printf("+================================================================+\n");
    printf("|                          Aplikasi I-Lab                        |\n");
    printf("+================================================================+\n");
}

void __menu(void)
{
    printf("| [1] Tambah Data                                                |\n");
    printf("| [2] Cari Data                                                  |\n");
    printf("| [3] Tampilkan Data                                             |\n");
    printf("| [4] Exit                                                       |\n");
}

void __back(void)
{
    printf("\n+================================================================+\n");
    clean_stdin();
    printf("[!] Klik enter untuk kembali ke menu");
    getchar();
}

void __notFound(void)
{
    for (int i = 5; i > 0; i--)
    {
        system("clear");
        __header();
        printf("[X] Menu tidak ditemukan, anda akan di alihkan ke halaman menu dalam %d detik\n", i);

        sleep(1);
    }
}

void __cekerName(char name[])
{
    char *loop;
    char tmp[200] = "";
    int number = 0;

    loop = strtok(name, " ");

    while (loop != NULL)
    {

        if (number > 2)
        {
            break;
        }

        strcat(tmp, loop);
        loop = strtok(NULL, " ");
        number++;
    }

    strcpy(name, tmp);
}

int __cekerNIM(char nim[])
{
    int lengthNim = strlen(nim);

    nim[0] = toupper(nim[0]);
    nim[1] = toupper(nim[1]);

    // cek panjang nim
    if (lengthNim != 17)
    {
        return 0;
    }
    // cek awalan if
    else if (nim[0] != 'I' && nim[1] != 'F')
    {
        return 0;
    }

    // cek digit
    for (int i = 2; i < lengthNim; i++)
    {
        if (!isdigit(nim[i]))
        {
            return 0;
        }
    }

    // cek duplikat
    for (int i = 0; i < length; i++)
    {
        if (strcmp(user[i].nim, nim) == 0 && user[i].status == 1)
        {
            return 1;
        }
    }

    return 2;
}

void __cekerClass(char *name)
{
    while (*name)
    {
        *name = toupper(*name);
        name++;
    }
}

int __cekerNull()
{

    if (length == 0)
    {
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        if (user[i].status == 1)
        {
            return 1;
        }
    }

    return 0;
}

int __cekerINdex(char nim[])
{
    for (int i = 0; i < length; i++)
    {
        if (strcmp(user[i].nim, nim) == 0 && user[i].status == 1)
        {
            return i;
        }
    }
}

void __keep(char nim[], char name[], char class[], char dosen[], int status, int i)
{
    strcpy(user[i].nim, nim);
    strcpy(user[i].name, name);
    strcpy(user[i].class, class);
    strcpy(user[i].dosen, dosen);

    user[i].status = status;
}

void __edit(int i)
{

    int menu;
    char name[100];
    char class[10];
    char dosen[100];

top:
    system("clear");
    __header();
    printf("|                            Edit Data                           |\n");
    printf("+================================================================+\n");
    printf("[~] Nama Lengkap        : %s\n", user[i].name);
    printf("[~] NIM                 : %s\n", user[i].nim);
    printf("[~] Kelas               : %s\n", user[i].class);
    printf("[~] Dosen Pembimbing    : %s\n", user[i].dosen);
    printf("+================================================================+\n");
    printf("[1] Edit Nama\n");
    printf("[2] Edit Kelas\n");
    printf("[3] Edit Dosen Pembimbing\n");
    printf("[4] Edit Semua\n");
    printf("[5] Kembali\n\n");

    printf("[~] Pilih Menu  : ");
    scanf("%d", &menu);

    system("clear");
    __header();
    printf("|                            Edit Data                           |\n");
    printf("+================================================================+\n");
    printf("[~] Nama Lengkap        : %s\n", user[i].name);
    printf("[~] NIM                 : %s\n", user[i].nim);
    printf("[~] Kelas               : %s\n", user[i].class);
    printf("[~] Dosen Pembimbing    : %s\n", user[i].dosen);
    printf("+================================================================+\n");

    switch (menu)
    {
    case 1:
        clean_stdin();
        printf("[+] Nama Lengkap     : ");
        scanf("%[^\n]s", name);

        // Ceker
        __cekerName(name);

        printf("+================================================================+\n");
        printf("[V] Berhasil memperbarui nama");
        __back();

        __keep(user[i].nim, name, user[i].class, user[i].dosen, 1, i);
        break;
    case 2:
        clean_stdin();
        printf("[+] Kelas            : ");
        scanf("%[^\n]s", class);

        // Ceker
        __cekerClass(class);

        printf("+================================================================+\n");
        printf("[V] Berhasil memperbarui kelas");
        __back();

        __keep(user[i].nim, user[i].name, class, user[i].dosen, 1, i);
        break;
    case 3:
        clean_stdin();
        printf("[+] Dosen Pembimbing : ");
        scanf("%[^\n]s", dosen);

        printf("+================================================================+\n");
        printf("[V] Berhasil memperbarui dosen pembimbing");
        __back();

        __keep(user[i].nim, user[i].name, user[i].class, dosen, 1, i);
        break;
    case 4:
        clean_stdin();
        printf("[+] Nama Lengkap     : ");
        scanf("%[^\n]s", name);

        // Ceker
        __cekerName(name);

        clean_stdin();
        printf("[+] Kelas            : ");
        scanf("%[^\n]s", class);

        // Ceker
        __cekerClass(class);

        clean_stdin();
        printf("[+] Dosen Pembimbing : ");
        scanf("%[^\n]s", dosen);

        printf("+================================================================+\n");
        printf("[V] Berhasil memperbarui data user");
        __back();

        __keep(user[i].nim, name, class, dosen, 1, i);
        break;
    case 5:
        main();
        break;
    default:
        __notFound();
        break;
    }

    goto top;
}

void __delete(int index)
{
    system("clear");
    __header();
    printf("|                            Edit Data                           |\n");
    printf("+================================================================+\n");
    printf("[~] Nama Lengkap        : %s\n", user[index].name);
    printf("[~] NIM                 : %s\n", user[index].nim);
    printf("[~] Kelas               : %s\n", user[index].class);
    printf("[~] Dosen Pembimbing    : %s\n", user[index].dosen);
    printf("+================================================================+\n");
    printf("[V] Berhasil menghapus NIM %s", user[index].nim);

    user[index].status = 0;

    __back();
}

void __add(void)
{
    char nim[18];
    char name[100];
    char class[10];
    char dosen[100];

    clean_stdin();
    printf("[+] Nama Lengkap     : ");
    scanf("%[^\n]s", name);

    // Ceker
    __cekerName(name);

nim:
    clean_stdin();
    printf("[+] NIM              : ");
    scanf("%s", nim);

    // Ceker
    if (__cekerNIM(nim) == 0)
    {
        printf("+================================================================+\n");
        printf("[X] Format nim salah!, silahkan masukan nim sesuai format berikut : IFXXXXXXXXXXXXXXX\n");
        sleep(3);
        system("clear");
        __header();
        printf("|                           TAMBAH DATA                          |\n");
        printf("+================================================================+\n");
        printf("[+] Nama Lengkap     : %s\n", name);
        goto nim;
    }
    else if (__cekerNIM(nim) == 1)
    {
        printf("+================================================================+\n");
        printf("[X] Nim sudah ada, silahkan cek di menu tampilkan data\n");
        sleep(3);
        system("clear");
        __header();
        printf("|                           TAMBAH DATA                          |\n");
        printf("+================================================================+\n");
        printf("[+] Nama Lengkap     : %s\n", name);
        goto nim;
    }

    clean_stdin();
    printf("[+] Kelas            : ");
    scanf("%[^\n]s", class);

    // Ceker
    __cekerClass(class);

    clean_stdin();
    printf("[+] Dosen Pembimbing : ");
    scanf("%[^\n]s", dosen);
    printf("+================================================================+\n");
    printf("[V] Berhasil menambah data");

    // keep struct
    __keep(nim, name, class, dosen, 1, length);
    ++length;

    __back();
}

void __search(void)
{
    char nim[18];

    if (__cekerNull() == 0)
    {
        printf("[x] Belum ada data, silahkan isi terlebih dahulu\n");
        sleep(2);
        main();
    }

nim:
    printf("[?] Masukan nim yang ingin di cari : ");
    scanf("%s", nim);

    if (__cekerNIM(nim) == 0)
    {
        printf("+================================================================+\n");
        printf("[X] Format nim salah!, silahkan masukan nim sesuai format berikut : IFXXXXXXXXXXXXXXX\n");
        sleep(3);
        system("clear");
        __header();
        printf("|                            Cari Data                           |\n");
        printf("+================================================================+\n");
        goto nim;
    }
    else if (__cekerNIM(nim) == 1)
    {
        int menu;
        int i = __cekerINdex(nim);

        printf("+================================================================+\n");
        printf("[~] Nama Lengkap        : %s\n", user[i].name);
        printf("[~] NIM                 : %s\n", user[i].nim);
        printf("[~] Kelas               : %s\n", user[i].class);
        printf("[~] Dosen Pembimbing    : %s\n", user[i].dosen);
        printf("+================================================================+\n");
        printf("[1] Edit Data\n");
        printf("[2] Hapus Data\n");
        printf("[3] Kembali\n\n");

        printf("[~] Pilih Menu  : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            __edit(i);
            break;
        case 2:
            __delete(i);
            break;
        case 3:
            main();
            break;
        default:
            __notFound();
            break;
        }
    }
    else
    {
        printf("+================================================================+\n");
        printf("[X] Nim tidak ditemukan!, silahkan masukan nim dengan benar\n");
        sleep(3);
        system("clear");
        __header();
        printf("|                            Cari Data                           |\n");
        printf("+================================================================+\n");
        goto nim;
    }
}

void __show(void)
{

    int no = 1;

    for (int i = 0; i < length; i++)
    {
        if (user[i].status == 1)
        {
            printf("                            ..:: %d ::.\n", no);
            printf("+================================================================+\n");
            printf("[~] Nama Lengkap        : %s\n", user[i].name);
            printf("[~] NIM                 : %s\n", user[i].nim);
            printf("[~] Kelas               : %s\n", user[i].class);
            printf("[~] Dosen Pembimbing    : %s\n", user[i].dosen);
            printf("+================================================================+\n");

            ++no;
        }
    }

    printf("[~] Total User  : %d", no - 1);
    __back();
}

void __pushToFIle(void)
{

    remove("db.txt");

    FILE *fp;
    fp = fopen("db.txt", "a");

    for (int i = 0; i < length; i++)
    {
        if (user[i].status == 1)
        {
            fprintf(fp, user[i].nim);
            fprintf(fp, ",");

            fprintf(fp, user[i].name);
            fprintf(fp, ",");

            fprintf(fp, user[i].class);
            fprintf(fp, ",");

            fprintf(fp, user[i].dosen);
            fprintf(fp, ",");
        }
    }

    fclose(fp);
}

void __pushToStruct(void)
{
    FILE *fp;
    fp = fopen("db.txt", "r");

    char allDb[10000];
    char *loop;
    char s[2] = ",";
    int cek = 1;

    fscanf(fp, "%[^\n]s", allDb);

    loop = strtok(allDb, s);

    while (loop != NULL)
    {
        if (cek == 1)
        {
            strcpy(user[length].nim, loop);
            cek++;
        }
        else if (cek == 2)
        {
            strcpy(user[length].name, loop);
            cek++;
        }
        else if (cek == 3)
        {
            strcpy(user[length].class, loop);
            cek++;
        }
        else if (cek == 4)
        {
            strcpy(user[length].dosen, loop);

            user[length].status = 1;
            ++length;
            cek = 1;
        }

        loop = strtok(NULL, s);
    }

    fclose(fp);
}