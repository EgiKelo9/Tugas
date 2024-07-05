// Nama     : I Made Gede Aryadana Baraja Putra
// NIM      : 2308561070
// Kelas    : D
// Prodi    : Informatika

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Nama[50];
    int BeratBadan;
    int TinggiBadan;
} DataPasien;

int main() {
    system("cls");

    // input jumlah pasien
    int JumlahPasien;
    printf("Ketik Jumlah Pasien : ");
    scanf("%d", &JumlahPasien);
    DataPasien Pasien[JumlahPasien];

    // input data setiap pasien
    for (int i = 0; i < JumlahPasien; i++) {
        printf("\nData %d\n", i+1);
        printf("Nama : ");
        getchar();
        fgets(Pasien[i].Nama,sizeof(Pasien[i].Nama), stdin);
        Pasien[i].Nama[strcspn(Pasien[i].Nama, "\n")] = 0;
        fflush(stdin);
        printf("Berat Badan : ");
        scanf("%d", &Pasien[i].BeratBadan);
        printf("Tinggi Badan : ");
        scanf("%d", &Pasien[i].TinggiBadan);
    }

    // Berat dan Tinggi Terendah
    int indexBerat = 0, indexTinggi = 0;
    int BeratTerendah = Pasien[0].BeratBadan;
    int TinggiTerendah = Pasien[0].TinggiBadan;
    for (int i = 1; i < JumlahPasien; i++) {
        if (Pasien[i].BeratBadan < BeratTerendah) {
            indexBerat = i;
            BeratTerendah = Pasien[indexBerat].BeratBadan;
        }
        if (Pasien[i].TinggiBadan < TinggiTerendah) {
            indexTinggi = i;
            TinggiTerendah = Pasien[indexTinggi].TinggiBadan;
        }
    }
    printf("\nBerat Terendah : %d (%s)", BeratTerendah, Pasien[indexBerat].Nama);
    printf("\nTinggi Terendah : %d (%s)", TinggiTerendah, Pasien[indexTinggi].Nama);

    return 0;
}