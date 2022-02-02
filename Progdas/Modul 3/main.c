#include "struct.h"

int main(void) {
    SetConsoleTitle("WARMINDO");

    SetColor(10);
    header();

    reset();

    do {
        up3:
        SetColor(11);
        menus();

        SetColor(15);
        printf("[~] Silahkan pilih pesanan anda : "); scanf("%s", pilih);

        reset();

        SetColor(11);
        toping();

        SetColor(14);
        char * token = strtok(pilih, ",");
        while (token != NULL){

            split = atoi(token) - 1;

            if(split >= 0 && split < 12){

                nota[loop].pesan = split;
            }

            loop++;
            token = strtok(NULL, ",");
        }

        for(int i = 0; i < loop; i++){
            int pesen = nota[i].pesan;


            if(nota[i].total == 0){
                printf("Anda memilih %s\n", menu[pesen].jenis);

                if(pesen < 7){
                    printf("[+] Pilih topping : "); scanf("%s", topping);
                    addTopping(topping, i);
                }

                printf("[+] Jumlah pesanan : "); scanf("%i", &nota[i].total);
            }
        }

        up:
        SetColor(11);
        printf("=======================================================\n");
        printf("1. Bayar\n");
        printf("2. Tambah pesanan\n");
        printf("=======================================================\n");

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
            printf("-------------------------------------------------------------------------\n");
            printf("No.\tJenis\t\t\tTopping\t\tQty\t\tHarga\n");
            printf("-------------------------------------------------------------------------\n");

            for (int i = 0; i < loop; i++) {
                printf("%i.\t%s%s\t%s\t\t %i\t\tRp.%i,-\n", i + 1, menu[nota[i].pesan].jenis, menu[nota[i].pesan].space, (strcmp(nota[i].toping, "") == 0) ? "   -" : nota[i].toping, nota[i].total, (menu[nota[i].pesan].harga + nota[i].toppingHarga) * nota[i].total);
                harga += (menu[nota[i].pesan].harga + nota[i].toppingHarga) * nota[i].total;
            }

            pajak = harga * ppn;
            grandTotal = harga + pajak;
            printf("-------------------------------------------------------------------------\n");
            printf("PPN 10%%\t\t\t\t\t\t\t\tRp.%.0f,-\n", pajak);
            printf("Total\t\t\t\t\t\t\t\tRp.%i,-\n", harga);
            printf("Grand Total\t\t\t\t\t\t\tRp.%.0f,-\n", grandTotal);

            if (bayar != 0 && bayar >= grandTotal) {
                printf("Tunai\t\t\t\t\t\t\t\tRp.%i,-\n", bayar);
                printf("Kembalian\t\t\t\t\t\t\tRp.%.0f,-\n", bayar - grandTotal);
                printf("-------------------------------------------------------------------------\n");
            } else if (bayar < grandTotal && bayar != 0) {
                printf("Tunai\t\t\t\t\t\t\t\tRp.%i,-\n", bayar);
                SetColor(11);
                printf("-------------------------------------------------------------------------\n");
                SetColor(4);
                printf("Maaf uang anda kurang Rp.%.0f!\n\n", grandTotal - bayar);
                SetColor(15);
                printf("[~] Nominal Pembayaran : ");
                scanf("%d", &bayar);
                harga = 0;
                goto up2;
            } else {
                printf("-------------------------------------------------------------------------\n");
                SetColor(15);
                printf("[~] Nominal Pembayaran : ");
                scanf("%d", &bayar);
                harga = 0;
                goto up2;
            }
            break;
        case 2:
            reset();
            goto up3;
            break;
        default:
            SetColor(4);
            reset();
            for (int i = 1; i < 6; i++) {
                reset();
                printf("Menu tidak ditemukan, anda akan diarahkan ke halaman konfirmasi dalam %d...", i);
                Sleep(1000);
            }
            reset();
            goto up;
        }

        SetColor(15);
        fflush(stdin);
        printf("Apakah anda ingin mengakhiri program ? [Y/N] : ");scanf("%c", &konfirmasi);

        switch (tolower(konfirmasi)) {
        case 'y':
            return 0;
            break;
        case 'n':

            for(int i = 0; i < loop; i++){
                strcpy(nota[i].toping, "\0");
                nota[i].toppingHarga = 0;
                nota[i].total = 0;
            }
            status = harga = bayar = loop = 0;
            reset();
            break;
        default:
            SetColor(4);
            reset();
            for (int i = 1; i < 6; i++) {
                reset();
                printf("Menu tidak ditemukan, anda akan diarahkan ke halaman nota dalam %d...", i);
                Sleep(1000);
            }
            harga = 0;
            goto up2;
        }

    } while (1);
}
