// Nama     : I Made Gede Aryadana Baraja Putra
// NIM      : 2308561070
// Kelas    : D
// Prodi    : Informatika

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inisialisasi struct mahasiswa
typedef struct {
    char Nama[100], NIM[11];
    int UKT, Nominal;
} Mhs;

int main() {
    system("cls");

    // memulai program dengan menginputkan maks antrian
    int max, front = 0, rear = 0, status = 0, count = 0;
    printf("Program Antrian Pembayaran UKT");
    printf("\nInput Maks Antrian : ");
    scanf("%d", &max);
    Mhs unud[max];

    // inisialisasi program dengan exit sebagai stopper
    char exit = 'T';
    do {
        // Menampilkan empat menu program
        printf("\nMenu : \n");
        printf("1. Tambah Antrian\n");
        printf("2. Proses Pembayaran\n");
        printf("3. Lihat Antrian\n");
        printf("4. Keluar\n");

        // meminta user memilih pilihan program
        int option;
        printf("\nPilihan : ");
        scanf("%d", &option);

        // switch case pilihan program
        switch(option) {
            case 1:
                if(status && front == rear) {
                    printf("Antrian telah penuh.\n");
                } else {
                    status = 1;
                    printf("Input Data Mahasiswa\n");
                    printf("Nama : ");
                    getchar();
                    fgets(unud[rear].Nama, sizeof(unud[rear].Nama), stdin);
                    unud[rear].Nama[strcspn(unud[rear].Nama, "\n")] = 0;
                    fflush(stdin);
                    printf("NIM : ");
                    fgets(unud[rear].NIM, sizeof(unud[rear].NIM), stdin);
                    unud[rear].NIM[strcspn(unud[rear].NIM, "\n")] = 0;
                    fflush(stdin);
                    printf("UKT : ");
                    scanf("%d", &unud[rear].UKT);
                    printf("Nominal : ");
                    scanf("%d", &unud[rear].Nominal);
                    printf("\nData berhasil ditambahkan.\n");
                    rear = (rear+1) % max;
                    count++;
                }
                break;
            case 2:
                if(!status && front == rear) {
                    printf("Antrian Kosong.\n");
                } else {
                    printf("Data Mahasiswa\n");
                    printf("Nama : %s\n", unud[front].Nama);
                    printf("NIM : %s\n", unud[front].NIM);
                    printf("UKT : %d\n", unud[front].UKT);
                    printf("Nominal : %d\n", unud[front].Nominal);
                    printf("Nominal bayar : ");
                    int pay;
                    scanf("%d", &pay);
                    if(pay >= unud[front].Nominal) {
                        printf("Kembalian : %d\n", pay - unud[front].Nominal);
                        front = (front+1) % max;
                        status = 0;
                        count--;
                    } else {
                        printf("Nominal pembayaran tidak mencukupi.\n");
                        printf("Perlu tambahan nominal sebesar %d untuk membayar lunas.\n", unud[front].Nominal - pay);
                        status = 1;
                    }
                }
                break;
            case 3:
                printf("| %-40s | %-11s | %-3s | %-16s |\n\n", "Nama", "NIM", "UKT", "Nominal");
                for(int i = front; i < front+count; i++) {
                    printf("| %-40s | %-11s | %-3d | Rp.%-13d |\n", unud[i%max].Nama, unud[i%max].NIM, unud[i%max].UKT, unud[i%max].Nominal);
                }
                break;
            case 4:
                printf("Apakah anda yakin akan keluar (Y/T) : ");
                scanf("%s", &exit);
                printf("Terimakasih.");
                break;
            default:
                printf("Mohon maaf saat ini pilihan program belum tersedia.\nSilakan memilih ulang program yang tersedia.\n");
                break;
        }
    } while(exit != 'Y');

    return 0;
}