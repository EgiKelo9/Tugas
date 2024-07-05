// Nama     : I Made Gede Aryadana Baraja Putra
// NIM      : 2308561070
// Kelas    : D
// Prodi    : Informatika

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Judul[100];
    int Halaman;
    char Penerbit[30];
} Buku;

int main() {

    // awal program
    system("cls");
    printf("Program tumpukan buku : \n");

    // input jumlah stack
    int maxStack;
    printf("Ketik jml maksimum tumpukan : ");
    scanf("%d", &maxStack);
    Buku buku[maxStack];

    // mulai program
    char exit = 'T';
    int index = -1;
    do {
        // output menu pilihan
        printf("Menu : \n");
        printf("1. Tambah Buku\n");
        printf("2. Ambil Buku\n");
        printf("3. Keluar\n");

        // input pilihan
        int cases;
        printf("\nPilihan : ");
        scanf("%d", &cases);

        // switch case pilihan
        switch(cases) {

            // menambahkan stack
            case 1:
                if(index < maxStack-1) {
                    index++;
                    printf("Ketik Judul Buku : ");
                    getchar();
                    fgets(buku[index].Judul,sizeof(buku[index].Judul),stdin);
                    buku[index].Judul[strcspn(buku[index].Judul, "\n")] = 0;
                    fflush(stdin);
                    printf("Jumlah Halaman : ");
                    scanf("%d", &buku[index].Halaman);
                    printf("Penerbit : ");
                    getchar();
                    fgets(buku[index].Penerbit,sizeof(buku[index].Penerbit),stdin);
                    buku[index].Penerbit[strcspn(buku[index].Penerbit, "\n")] = 0;
                    fflush(stdin);
                    printf("\n");
                } else printf("Tumpukan penuh\n\n");
                break;

            // mengeluarkan stack
            case 2:
                if(index >= 0) {
                    char pop;
                    printf("Anda Yakin (Y/T) : ");
                    scanf("%s", &pop);
                    if(pop == 'Y') {
                        printf("Buku dengan judul %s sudah diambil\n\n", buku[index].Judul);
                        index--;
                    } else break;
                } else printf("Tumpukan kosong\n\n");
                break;

            // keluar program
            case 3:
                printf("Anda Yakin (Y/T) : ");
                scanf("%s", &exit);
                if(exit == 'Y') printf("Terima kasih");
                break;

            // default program
            default:
                printf("Program tidak tersedia\n\n");
                break;
        }
    } while(exit != 'Y');

    return 0;
}