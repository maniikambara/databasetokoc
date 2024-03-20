#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max 100

typedef struct {
    int kode;
    char nama[50];
    char material[50];
    int jumlah;
    float harga;
} Barang;

Barang In[max];
int jum=0;

void menu() {
    system("cls");
    printf("+--------------------------------+\n\n");
    printf("\tDATABASE TOKO MEBEL \n");
    printf("\n+--------------------------------+\n\n");
    printf("|\t\t \t\t |\n");
    printf("|\t1. Input Barang \t |\n");
    printf("|\t2. Lihat Stok Barang \t |\n");
    printf("|\t3. Exit \t\t |\n");
    printf("|\t\t \t\t |\n");
    printf("\n+--------------------------------+\n\n");
    printf("  Dibuat oleh Manik (2308561017) \n");
    printf("\n+--------------------------------+\n\n");

    time_t waktu_saat_ini = time(NULL);
    struct tm* waktu_lokal = localtime(&waktu_saat_ini);
    printf("%02d/%02d/%d\t\t     %02d:%02d\n",
           waktu_lokal->tm_mday, waktu_lokal->tm_mon + 1, waktu_lokal->tm_year + 1900,
           waktu_lokal->tm_hour, waktu_lokal->tm_min);
}

void inputBarang() {
    system("cls");
    int banyakBarang;
    printf("\n\t-- INPUT BARANG --\n\n");
    printf("Banyaknya Barang yang akan Anda masukkan: ");
    scanf("%d", &banyakBarang);
    getchar();

    for (int i = 0; i < banyakBarang; i++) {
        printf("\n:: Kode Barang\t\t : [%d] : ", i+1);
        scanf("%d", &In[jum].kode);
        getchar();

        printf(":: Nama Barang\t\t : [%d] : ", i+1);
        fgets(In[jum].nama, sizeof(In[jum].nama), stdin);
        In[jum].nama[strcspn(In[jum].nama, "\n")] = '\0';

        printf(":: Bahan Dasar\t\t : [%d] : ", i+1);
        fgets(In[jum].material, sizeof(In[jum].material), stdin);
        In[jum].material[strcspn(In[jum].material, "\n")] = '\0';

        printf(":: Jumlah\t\t : [%d] : ", i+1);
        scanf("%d", &In[jum].jumlah);
        getchar();

        printf(":: Harga per Unit\t : [%d] : Rp. ", i+1);
        scanf("%f", &In[jum].harga);
        getchar();

        jum++;
    }

    printf("\nData barang berhasil disimpan...\n");
    system("pause");
}

void stokBarang() {
    system("cls");
    printf("\n\t-- PERSEDIAAN BARANG --");
    if (jum == 0) {
        printf("\n\nTidak ada barang...\n");
    } else {
        for (int i = 0; i < jum; i++) {
            printf("\n\nData Barang Ke %d : ", i+1);
            printf("\n:: Kode Barang\t\t : %03d ", In[i].kode);
            printf("\n:: Nama Barang\t\t : %s ", In[i].nama);
            printf("\n:: Bahan Dasar\t\t : %s ", In[i].material);
            printf("\n:: Jumlah\t\t : %d ", In[i].jumlah);
            printf("\n:: Harga per Unit\t : Rp. %.2f ", In[i].harga);
        }
    }

    printf("\n");
    system("pause");
}

int main() {
    int pilihan;
    do {
        menu();
        printf("\n\tPILIH [1,2,3] : ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                inputBarang();
                break;
            case 2:
                stokBarang();
                break;
            case 3:
                printf("\n\tTerima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid...\n");
                system("pause");
                break;
        }
    } while (pilihan != 3);

    return 0;
}