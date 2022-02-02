void selectionShort(int A[], int n) {
    int temp;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

void inputValue(int n)

    int array[n][n];
    int save[n*n];
    int no = 1, index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d. Masukan index matrix [%d][%d] : ", no, i, j);
            scanf("%d", &array[i][j]);
            no++;
        }
    }
    printf("======================================================================================================================================\n");
    (n == 2) ? printf("[~] Matriks\n\n __    __\n|\t |\n") : printf("[~] Matriks\n\n __\t       __\n|\t\t |\n");
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++) {
            printf("%d", array[i][j]);
            ((n == 2 && j == 0) || (n == 3 && j != 2 )) ? printf("\t") : printf("|");
            save[index] = array[i][j];
            index++;

        }
        printf("\n");
    }
    (n == 2) ? printf("|__    __|\n") : printf("|__\t       __|\n");

    selectionShort(save, index);

    printf("======================================================================================================================================\n");
    printf("[~] Sorting Array\n\n");

    printf("[+] Array Ascending  : ");
    for(int i = 0; i < index; i++){
        printf("%d", save[i]);
        (index - i == 1) ? printf("\n") : printf(", ");
    }

    printf("[+] Array Descending : ");
    for(int i = index-1 ; i >= 0 ; i--){
        printf("%d", save[i]);
        (i == 0) ? printf("\n") : printf(", ");
    }

    printf("======================================================================================================================================\n");
    printf("[~] Bilangan Terkecil : %d\n", save[0]);
    printf("[~] Bilangan Terbesar : %d\n", save[index-1]);

}

void notfound(){

    for(int i = 5; i >= 0; i--){
        system("cls");
        header();
        printf("Menu tidak ditemukan, anda akan di redirect ke halaman utama dalam %d detik...", i);
        sleep(1);
    }
}

int kegiatan2(void) {

    SetConsoleTitle("Praktik Modul 4 Kegiatan 2");

    int menu;
    char konfirmasi;
    top:
    header();
    printf("[~] Pilih salah satu menu di bawah ini\n\n");
    printf("[1] Ordo 2x2\n");
    printf("[2] Ordo 3x3\n\n");
    printf("Pilih : "); scanf("%d", &menu);
    printf("======================================================================================================================================\n");

    switch (menu) {
    case 1:
        inputValue(2);
        break;
    case 2:
        inputValue(3);
        break;
    default:
        notfound();
        system("cls");
        goto top;
    }

    printf("======================================================================================================================================\n");

    printf("Apakah anda ingin mengakhiri program [y/n] ? : "); scanf(" %c", &konfirmasi);
    switch(tolower(konfirmasi)){
        case 'y':
            return 0;
            break;
        case 'n':
            system("cls");
            goto top;
            break;
        default:
            notfound();
            system("cls");
            goto top;
    }
}
