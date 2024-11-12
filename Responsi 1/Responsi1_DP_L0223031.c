#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATATAN 100

struct Catatan {
    char judul[50];
    char isi[200];
};

struct Catatan catatan[MAX_CATATAN];

int jumlahCatatan = 0;

// Fungsi untuk menambahkan catatan baru
void tambahCatatan() {
    
    printf("\nMENAMBAHKAN CATATAN:\n");
    
    if (jumlahCatatan < MAX_CATATAN) {
        char judulBaru[50];

        // Meminta pengguna untuk memasukkan judul catatan
        printf("\nMasukkan judul catatan: ");
        scanf(" %[^\n]", judulBaru);

        // Mengecek apakah judul sudah ada dalam catatan
        for (int i = 0; i < jumlahCatatan; i++) {
            if (strcmp(catatan[i].judul, judulBaru) == 0) {
                // Jika judul sudah ada, meminta pengguna untuk mengganti judul
                printf("Judul '%s' sudah ada.\nMohon masukkan judul baru: ", judulBaru);
                scanf(" %[^\n]", judulBaru);
                // Kembali memeriksa apakah judul baru sudah ada
                i = -1;  // Mengulang pemeriksaan dari awal
            }
        }

        // Memasukkan isi catatan setelah mendapatkan judul yang unik
        printf("Masukkan isi catatan: \n");
        scanf(" %[^\n]", catatan[jumlahCatatan].isi);

        // Menyimpan judul yang sudah diverifikasi ke dalam catatan
        strcpy(catatan[jumlahCatatan].judul, judulBaru);

        jumlahCatatan++;
        printf("\n[Catatan berhasil ditambahkan!]\n");
    } else {
        printf("\n[Maaf, batas maksimum catatan telah tercapai.]\n");
    }
}

// Fungsi untuk menampilkan semua catatan
void tampilkanSemuaCatatan() {
    
    printf("\nSEMUA CATATAN LUTPI:\n");
    
    if (jumlahCatatan > 0) {
        for (int i = 0; i < jumlahCatatan; i++) {
            printf("\nJudul: %s\n", catatan[i].judul);
            printf("Isi: %s\n", catatan[i].isi);
        }
    } else {
        printf("\n[ Belum ada catatan yang dimasukkan. ]\n");
    }
}

// Fungsi untuk menampilkan satu catatan berdasarkan judul
void tampilkanSatuCatatan() {
    
    printf("\nMENAMPILKAN CATATAN:\n");

    char cariJudul[50];
    printf("\nMasukkan judul catatan yang ingin ditampilkan: ");
    scanf(" %[^\n]", cariJudul);

    struct Catatan *ptrCatatan = NULL;

    for (int i = 0; i < jumlahCatatan; i++) {
        if (strcmp(catatan[i].judul, cariJudul) == 0) {
            ptrCatatan = &catatan[i];
            break;
        }
    }

    if (ptrCatatan != NULL) {
        printf("\nCATATAN YANG DICARI:\n");
        printf("\nJudul: %s\n", ptrCatatan->judul);
        printf("Isi: %s\n", ptrCatatan->isi);
    } else {
        printf("\n[Catatan dengan judul '%s' tidak ditemukan.]\n", cariJudul);
    }
}

// Fungsi untuk mengganti isi catatan
void gantiCatatan() {
    
    printf("\nMENGGANTI ISI CATATAN:\n");
    
    char cariJudul[50];
    printf("\nMasukkan judul catatan yang ingin diganti: ");
    scanf(" %[^\n]", cariJudul);

    struct Catatan *ptrCatatan = NULL;

    for (int i = 0; i < jumlahCatatan; i++) {
        if (strcmp(catatan[i].judul, cariJudul) == 0) {
            ptrCatatan = &catatan[i];
            break;
        }
    }

    if (ptrCatatan != NULL) {
        printf("Masukkan isi catatan yang baru: \n");
        scanf(" %[^\n]", ptrCatatan->isi);
        printf("\n[Catatan berhasil diganti!]\n");
    } else {
        printf("\n[Catatan dengan judul '%s' tidak ditemukan.]\n", cariJudul);
    }
}

// Fungsi untuk menghapus catatan
void hapusCatatan() {
    
    printf("\nMENGHAPUS CATATAN:\n");
    
    char cariJudul[50];
    printf("\nMasukkan judul catatan yang ingin dihapus: ");
    scanf(" %[^\n]", cariJudul);

    int catatanDitemukan = 0;

    for (int i = 0; i < jumlahCatatan; i++) {
        if (strcmp(catatan[i].judul, cariJudul) == 0) {
            // Menggeser catatan ke sebelumnya untuk menutup celah yang dihapus
            for (int j = i; j < jumlahCatatan - 1; j++) {
                strcpy(catatan[j].judul, catatan[j + 1].judul);
                strcpy(catatan[j].isi, catatan[j + 1].isi);
            }
            jumlahCatatan--;
            printf("\n[Catatan berhasil dihapus!]\n");
            catatanDitemukan = 1;
            break;
        }
    }

    if (!catatanDitemukan) {
        printf("\n[Catatan dengan judul '%s' tidak ditemukan.]\n", cariJudul);
    }
}

int main() {
    int pilihan;

    while (1) {
        printf("\n===== NOTE FOR LUTPI =====\n");
        printf("\nMENU:");
        printf("\n1. Tambah Catatan");
        printf("\n2. Tampilkan Semua Catatan");
        printf("\n3. Tampilkan Satu Catatan");
        printf("\n4. Ganti Catatan");
        printf("\n5. Hapus Catatan");
        printf("\n6. Keluar\n");
        printf("\nPilih menu (1-6): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahCatatan();
                break;
            case 2:
                tampilkanSemuaCatatan();
                break;
            case 3:
                tampilkanSatuCatatan();
                break;
            case 4:
                gantiCatatan();
                break;
            case 5:
                hapusCatatan();
                break;
            case 6:
                printf("\nProgram diberhentikan. Dadah Lutpi!");
                exit(0);
            default:
                printf("\nPerintah tidak valid. Silakan masukkan perintah yang benar.\n");
        }
    }

    return 0;
}
