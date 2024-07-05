// Nama     : I Made Gede Aryadana Baraja Putra
// NIM      : 2308561070
// Kelas    : D
// Prodi    : Informatika

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Nama[30];
    char NIM[11];
    int UTS, UAS, Tugas, Kuis;
    float NilaiMutu;
} Mahasiswa;

int main() {
    system("cls");

    // input banyaknya mahasiswa
    int totalMhs;
    printf("Jumlah Mahasiswa : ");
    scanf("%d", &totalMhs);
    Mahasiswa Mhs[totalMhs];

    // input data setiap mahasiswa
    printf("\nKetik Data Mahasiswa : \n");
    for(int i = 0; i < totalMhs; i++) {

        // input identitas setiap mahasiswa
        printf("Nama : ");
        getchar();
        fgets(Mhs[i].Nama,sizeof(Mhs[i].Nama),stdin);
        Mhs[i].Nama[strcspn(Mhs[i].Nama, "\n")] = 0;
        fflush(stdin);
        printf("NIM : ");
        fgets(Mhs[i].NIM,sizeof(Mhs[i].NIM),stdin);
        Mhs[i].NIM[strcspn(Mhs[i].NIM, "\n")] = 0;
        fflush(stdin);

        // input nilai setiap mahasiswa
        printf("UTS : ");
        scanf("%d", &Mhs[i].UTS);
        printf("UAS : ");
        scanf("%d", &Mhs[i].UAS);
        printf("Tugas : ");
        scanf("%d", &Mhs[i].Tugas);
        printf("Kuis : ");
        scanf("%d", &Mhs[i].Kuis);

        // menghitung nilai mutu setiap mahasiswa
        Mhs[i].NilaiMutu = (Mhs[i].UAS + Mhs[i].UTS) * 0.3 + (Mhs[i].Tugas + Mhs[i].Kuis) * 0.2;
        printf("Nilai Mutu : %.2f\n", Mhs[i].NilaiMutu);
        printf("\n");
    }

    // nilai mutu tiap mahasiswa
    printf("Nilai Mutu Setiap Mahasiswa : \n");
    for(int i = 0; i < totalMhs; i++) {
        if(Mhs[i].NilaiMutu < 30) printf("Nilai Mutu %s adalah %.2f dengan grade E\n", Mhs[i].Nama, Mhs[i].NilaiMutu);
        else if(Mhs[i].NilaiMutu < 50) printf("Nilai Mutu %s adalah %.2f dengan grade D\n", Mhs[i].Nama, Mhs[i].NilaiMutu);
        else if(Mhs[i].NilaiMutu < 65) printf("Nilai Mutu %s adalah %.2f dengan grade C\n", Mhs[i].Nama, Mhs[i].NilaiMutu);
        else if(Mhs[i].NilaiMutu < 80) printf("Nilai Mutu %s adalah %.2f dengan grade B\n", Mhs[i].Nama, Mhs[i].NilaiMutu);
        else if(Mhs[i].NilaiMutu < 100) printf("Nilai Mutu %s adalah %.2f dengan grade A\n", Mhs[i].Nama, Mhs[i].NilaiMutu);
    }

    // nilai mutu total mahasiswa
    int TotalUTS = 0, TotalUAS = 0, TotalTugas = 0, TotalKuis = 0;
    for(int i = 0; i < totalMhs; i++) {
        TotalUTS += Mhs[i].UTS;
        TotalUAS += Mhs[i].UAS;
        TotalTugas += Mhs[i].Tugas;
        TotalKuis += Mhs[i].Kuis;
    }
    float NilaiMutuTotal = ((TotalUTS + TotalUAS) * 0.3 + (TotalTugas + TotalKuis) * 0.2)/totalMhs;
    if(NilaiMutuTotal < 30) printf("\nNilai Mutu Total adalah %.2f dengan grade E\n", NilaiMutuTotal);
    else if(NilaiMutuTotal < 50) printf("\nNilai Mutu Total adalah %.2f dengan grade D\n", NilaiMutuTotal);
    else if(NilaiMutuTotal < 65) printf("\nNilai Mutu Total adalah %.2f dengan grade C\n", NilaiMutuTotal);
    else if(NilaiMutuTotal < 80) printf("\nNilai Mutu Total adalah %.2f dengan grade B\n", NilaiMutuTotal);
    else if(NilaiMutuTotal < 100) printf("\nNilai Mutu Total adalah %.2f dengan grade A\n", NilaiMutuTotal);

    return 0;
}