#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void linearProbing(int n ,int linear[], int num) {
    // set variabel tambahan
    int i = 0;
    // while loop sejumlah n
    while(i < n) {
        // f(x) = (x + i) mod n
        int index = (num + i) % n;
        // tambah data ke array
        if(linear[index] == -1) {
            linear[index] = num;
            break;
        }
        // increment
        i++;
    }
}

void quadraticProbing(int n, int quadratic[n], int num) {
    // set variabel tambahan
    int i = 0;
    // while loop sejumlah n
    while (i < n) {
        // f(x) = (x +/- i) mod n
        int index1 = (num + i*i) % n;
        int index2 = (num - i*i) % n;
        // tambah data ke array
        if(quadratic[index1] == -1) {
            quadratic[index1] = num;
            break;
        } else if(quadratic[index2] == -1) {
            quadratic[index2] = num;
            break;
        }
        // increment
        i++;
    }
}

int main() {
    // input jumlah bilangan
    int n;
    printf("Ketik Jumlah Bilangan : ");
    scanf("%d", &n);
    // set default nilai array
    int num[n], linear[n], quadratic[n];
    for(int i = 0; i < n; i++) {
        linear[i] = -1;
        quadratic[i] = -1;
    }
    // input bilangan dan panggil fungsi hash
    for(int i = 0; i < n; i++) {
        printf("Bil. %d : ", i+1);
        scanf("%d", &num[i]);
        linearProbing(n, linear, num[i]);
        quadraticProbing(n, quadratic, num[i]);
    }
    // cetak hasil hashing
    printf("\nData Tersimpan (Linear Probing)\n");
    for(int i = 0; i < n; i++) {
        printf("Index %d : %d\n", i, linear[i]);
    }
    printf("\nData Tersimpan (Quadratic Probing)\n");
    for(int i = 0; i < n; i++) {
        printf("Index %d : %d\n", i, quadratic[i]);
    }
    return 0;
}