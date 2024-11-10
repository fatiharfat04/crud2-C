#include <stdio.h>
#include <string.h>

// struct/template data untuk Teman
typedef struct {
    char nama[50];
    char nomorTelepon[15];
} Teman;

// array untuk menyimpan data
#define MAX 100
Teman daftarTeman[MAX]; 
int jumlahTeman = 0;
//---------------------------//


// fungsi tambah/create data
void createTeman(){
    if (jumlahTeman < MAX)
    {
        Teman temanBaru;

        // input nama
        printf("masukkan nama:\n");
        scanf(" %[^\n]s", temanBaru.nama);

        // input nomor telepon
        printf("masukkan nomor telepon:\n");
        scanf(" %[^\n]s", temanBaru.nomorTelepon);

        // tambahkan data teman ke dalam array
        daftarTeman[jumlahTeman] = temanBaru;
        jumlahTeman++;

        printf("Teman berhasil ditambahkan!\n");
    } else {
        printf("Teman sudah penuh!\n");
    }
}

// fungsi baca/read data
void readTeman(){
    if (jumlahTeman > 0)
    {
        printf("\nData Teman:\n");
        for (int i = 0; i < jumlahTeman; i++) {
            printf("Teman ke-%d\n", i + 1);
            printf("Nama: %s\n", daftarTeman[i].nama);
            printf("Nomor Telepon: %s\n\n", daftarTeman[i].nomorTelepon);
        }
    } else {
        printf("belum ada data Teman yang disimpan!\n");
    }
}

// fungsi update/ubah data
void updateTeman(){
    int index;

    printf("masukkan id teman yang ingin di-update (mulai dari 1): ");
    scanf("%d", &index);
    index--; // kurangi 1 untuk menyesuaikan dengan indeks array (dimulai dari 0)

    if (index >= 0 && index < jumlahTeman)
    {
        // input data baru
        printf("masukkan nama teman baru: ");
        scanf(" %[^\n]s", daftarTeman[index].nama);
        printf("masukkan nomor telepon teman baru: ");
        scanf(" %[^\n]s", daftarTeman[index].nomorTelepon);

        printf("data teman berhasil diubah!\n");
    } else {
        printf("id teman tidak valid!\n");
    }

}

// fungsi delete/hapus data
void deleteTeman(){
    int index;

    printf("masukkan id teman yang ingin dihapus (mulai dari 1): ");
    scanf("%d", &index);
    index--; // kurangi 1 untuk menyesuaikan dengan indeks array (dimulai dari 0)

    if (index >= 0 && index < jumlahTeman)
    {
        // geser elemen-elemen setelah teman yang dihapus ke kiri
        for (int i = index; i < jumlahTeman - 1; i++)
        {
            daftarTeman[i] = daftarTeman[i + 1];
        }
        jumlahTeman--; // kurangi jumlah teman

        printf("data teman berhasil dihapus!\n");
    } else {
        printf("id teman tidak valid!\n");
    }
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    printf("\n===== MENU CRUD Teman =====\n");
    printf("1. Tambah Teman\n");
    printf("2. Lihat Semua Teman\n");
    printf("3. Update Data Teman\n");
    printf("4. Hapus Data Teman\n");
    printf("5. Keluar\n");
    printf("Pilih opsi: ");
}

int main() {
    int pilihan;

    do {
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                createTeman();
                break;
            case 2:
                readTeman();
                break;
            case 3:
                updateTeman();
                break;
            case 4:
                deleteTeman();
                break;
            case 5:
                printf("Keluar dari program...\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (pilihan != 5);

    return 0;
}
