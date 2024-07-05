// Nama     : I Made Gede Aryadana Baraja Putra
// NIM      : 2308561070
// Kelas    : D
// Prodi    : Informatika

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Nama[100];
    char NIM[11];
    int UKT, Nominal;
    struct Mhs *next;
} Mhs;

int main() {
    system("cls");
    Mhs *head = NULL, *tail = NULL, *new;
    printf("Program Antrian Pembayaran UKT\n");
    printf("Input maks antrian : ");
    int max, count = 0;
    scanf("%d", &max);
    char exit = 'T';
    do {
        printf("\nMenu : \n");
        printf("1. Tambah Antrian\n");
        printf("2. Proses Pembayaran\n");
        printf("3. Lihat Antrian\n");
        printf("4. Keluar\n");
        int option;
        printf("\nPilihan : ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                if(count == max) {
                    printf("Maaf, antrian penuh.\n");
                } else {
                    count++;
                    new = (Mhs *)malloc(sizeof(Mhs));
                    printf("\nInput Data Mahasiswa\n");
                    printf("Nama : ");
                    getchar();
                    fgets(new->Nama, sizeof(new->Nama), stdin);
                    new->Nama[strcspn(new->Nama, "\n")] = 0;
                    printf("NIM : ");
                    fgets(new->NIM, sizeof(new->NIM), stdin);
                    new->NIM[strcspn(new->NIM, "\n")] = 0;
                    printf("UKT : ");
                    scanf("%d", &(new->UKT));
                    printf("Nominal : ");
                    scanf("%d", &(new->Nominal));
                    new->next = NULL;
                    printf("Data berhasil ditambahkan.\n");
                    if (head == NULL) {
                        head = new;
                        tail = new;
                    } else {
                        tail->next = new;
                        tail = new;
                    }
                }
                break;
            case 2:
                if (head == NULL && !count) {
                    printf("Antrian kosong.\n");
                } else {
                    printf("\nData Mahasiswa\n");
                    printf("Nama : %s\n", head->Nama);
                    printf("NIM : %s\n", head->NIM);
                    printf("UKT : %d\n", head->UKT);
                    printf("Nominal : %d\n", head->Nominal);
                    printf("Nominal bayar : ");
                    int pay;
                    scanf("%d", &pay);
                    if (pay >= head->Nominal) {
                        printf("Kembalian : %d\n", pay - head->Nominal);
                        Mhs *temp = head;
                        head = head->next;
                        free(temp);
                        count--;
                    } else {
                        printf("Nominal pembayaran tidak mencukupi.\n");
                        printf("Perlu tambahan nominal sebesar %d untuk membayar lunas.\n", head->Nominal - pay);
                    }
                }
                break;
            case 3:
                if (head == NULL && !count) {
                    printf("Antrian kosong.\n");
                } else {
                    Mhs *temp = head;
                    printf("| %-40s | %-11s | %-3s | %-16s |\n\n", "Nama", "NIM", "UKT", "Nominal");
                    while (temp != NULL) {
                        printf("| %-40s | %-11s | %-3d | Rp.%-13d |\n", temp->Nama, temp->NIM, temp->UKT, temp->Nominal);
                        temp = temp->next;
                    }
                }
                break;
            case 4:
                printf("Apakah anda yakin akan keluar (Y/T) : ");
                scanf(" %c", &exit);
                printf("Terimakasih.");
                break;
            default:
                printf("Mohon maaf saat ini pilihan program belum tersedia.\nSilakan memilih ulang program yang tersedia.\n");
                break;
        }
    } while (exit != 'Y');

    return 0;
}