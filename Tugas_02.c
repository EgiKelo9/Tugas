// Nama     : I Made Gede Aryadana Baraja Putra
// NIM      : 2308561070
// Kelas    : D
// Prodi    : Informatika

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Nomor[11];
    char Nama[30];
    int Teori, Praktek, Total;
    float Rata;
} Peserta;

int main() {
    system("cls");

    // input banyaknya peserta
    int totalPeserta;
    printf("Jumlah Peserta : ");
    scanf("%d", &totalPeserta);
    Peserta peserta[totalPeserta];

    // input data setiap peserta
    printf("\nKetik Data Peserta Kompetisi : ");
    for(int i = 0; i < totalPeserta; i++) {
        printf("\nNo Peserta : ");
        getchar();
        fgets(peserta[i].Nomor,sizeof(peserta[i].Nomor), stdin);
        peserta[i].Nomor[strcspn(peserta[i].Nomor, "\n")] = 0;
        fflush(stdin);
        printf("Nama : ");
        fgets(peserta[i].Nama,sizeof(peserta[i].Nama), stdin);
        peserta[i].Nama[strcspn(peserta[i].Nama, "\n")] = 0;
        fflush(stdin);
        printf("Nilai Teori : ");
        scanf("%d", &peserta[i].Teori);
        printf("Nilai Praktek : ");
        scanf("%d", &peserta[i].Praktek);

        // total nilai peserta
        peserta[i].Total = peserta[i].Teori + peserta[i].Praktek;
        printf("Total Nilai : %d\n", peserta[i].Total);

        // rata-rata nilai peserta
        peserta[i].Rata = peserta[i].Total / 2.0;
        printf("Rata-rata : %.2f\n", peserta[i].Rata);
        
        // status peserta
        if(peserta[i].Rata >= 60) printf("Status : Lulus\n");
        else printf("Status : Gagal\n");
    }

    return 0;
}