void header(){

    printf(" /$$$$$$$                   /$$        /$$     /$$ /$$             /$$      /$$                 /$$           /$$       /$$   /$$\n");
    printf("| $$__  $$                 | $$       | $$    |__/| $$            | $$$    /$$$                | $$          | $$      | $$  | $$\n");
    printf("| $$  \\ $$/$$$$$$  /$$$$$$ | $$   /$$/$$$$$$   /$$| $$   /$$      | $$$$  /$$$$  /$$$$$$   /$$$$$$$ /$$   /$$| $$      | $$  | $$\n");
    printf("| $$$$$$$/$$__  $$|____  $$| $$  /$$/_  $$_/  | $$| $$  /$$/      | $$ $$/$$ $$ /$$__  $$ /$$__  $$| $$  | $$| $$      | $$$$$$$$\n");
    printf("| $$____/ $$  \\__/ /$$$$$$$| $$$$$$/  | $$    | $$| $$$$$$/       | $$  $$$| $$| $$  \\ $$| $$  | $$| $$  | $$| $$      |_____  $$\n");
    printf("| $$    | $$      /$$__  $$| $$_  $$  | $$ /$$| $$| $$_  $$       | $$\\  $ | $$| $$  | $$| $$  | $$| $$  | $$| $$            | $$\n");
    printf("| $$    | $$     |  $$$$$$$| $$ \\  $$ |  $$$$/| $$| $$ \\  $$      | $$ \\/  | $$|  $$$$$$/|  $$$$$$$|  $$$$$$/| $$            | $$\n");
    printf("|__/    |__/      \\_______/|__/  \\__/  \\___/  |__/|__/  \\__/      |__/     |__/ \\______/  \\_______/ \\______/ |__/            |__/\n");
    printf("======================================================================================================================================\n");
    printf("Nama\t: Muhammad Novel\n");
    printf("Kelas\t: Informatika G\n");
    printf("NIM\t: 202110370311320\n");
    printf("Aslab\t: Muhammad Zulfiqor Lilhaq\n");
    printf("======================================================================================================================================\n");

}

void printArray(int array[], int length){

    for (int i = 0; i < length; i++) {
        printf("\t   %d\t\t|", array[i]);
    }
    printf("\n ===============================================================================================\n");
}

int kegiatan1(void) {
    SetConsoleTitle("Tugas Modul 4");
    header();

    int boruto[] = {
        85,
        90,
        86
    };
    int sarada[] = {
        84,
        90,
        89
    };

    const int length = sizeof(boruto) / 4;

    printf("\t\t\t\tTabel Nilai Ujian Pemrograman Dasar\n");
    printf("\n ===============================================================================================\n");
    printf("|\tNama\t\t|\tUjian 1\t\t|\tUjian 2\t\t|\tUjian 3\t\t|\n");
    printf(" ===============================================================================================\n");
    printf("|\tBoruto\t\t|");
    printArray(boruto, length);
    printf("|\tSarada\t\t|");
    printArray(sarada, length);

    printf("\n\n");

    printf("\t    Tabel Perbandingan Nilai Ujian Boruto & Sarada\n");
    printf("\n =======================================================================\n");
    printf("|\tUjian 1\t\t|\tUjian 2\t\t|\tUjian 3\t\t|\n");
    printf(" =======================================================================\n");
    for (int i = 0; i < length; i++) {
        printf("|\t   %d\t\t", (boruto[i] > sarada[i]) ? 1 : 0);
    }
    printf("|\n =======================================================================\n\n");

    printf("*1 = Nilai Boruto lebih besar dari sarada\n");
    printf("*0 = Nilai Boruto sama dengan nilai sarada atau kurang dari sarada\n\n");

    fflush(stdin);
    printf("[!] Klik enter untuk mengakhiri program..."); getchar();
    return 0;
}
