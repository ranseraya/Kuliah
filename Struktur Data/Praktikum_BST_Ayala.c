#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mahasiswa {
    long long npm;
    char nama[20];
    char prodi[20];
    float ipk;
    struct mahasiswa* left;
    struct mahasiswa* right;
};

typedef struct mahasiswa mhs;

mhs *newData(long long npm, char *nama, char *prodi, float ipk);
mhs *insertData(mhs *mahasiswa, long long npm, char *nama, char *prodi, float ipk, int *status);
mhs *deleteData(mhs *mahasiswa, long long npm);
mhs *predecessor(mhs *mahasiswa);
void searching(mhs *mahasiswa, long long npm);
void printData(mhs *mahasiswa, int *i);

int isRunning = 1;

int main() {
    int i, jumlah, pilihan, status;
    long long cari, delKey;
    mhs *mahasiswa = NULL;

    while (isRunning) {
        system("cls");
        printf("=== Managemen Mahasiswa BST ====\n");
        printf("1. Menambah data mahasiswa\n");
        printf("2. Menghapus data mahasiswa\n");
        printf("3. Menampilkan semua data mahasiswa\n");
        printf("4. Mencari data mahasiswa\n");
        printf("5. Keluar Program\n");
        printf("Masukkan nomor program: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                system("cls");
                printf("======= INSERT DATA =========\n");
                printf("\nMasukkan jumlah data: ");
                scanf("%d", &jumlah);
                for (int i = 1; i <= jumlah; i++) {
                    char tempNama[20] = {0};  
                    char tempProdi[20] = {0};
                    long long npm;
                    float ipk;

                    printf("Data ke-%d:\n", i);
                    printf("Masukkan npm: ");
                    scanf("%lld", &npm); 
                    printf("Masukkan nama: ");
                    scanf("%19s", tempNama);
                    printf("Masukkan prodi: ");
                    scanf("%19s", tempProdi);
                    printf("Masukkan IPK: ");
                    scanf("%f", &ipk);

                    mahasiswa = insertData(mahasiswa, npm, tempNama, tempProdi, ipk, &status);
                    if (status == 0) {
                        printf("Mahasiswa dengan npm %lld sudah ada! Data tidak ditambahkan.\n", npm);
                    } else {
                        printf("Data mahasiswa berhasil ditambahkan.\n");
                    }
                }
                system("pause");
                break;
            case 2:
                system("cls");
                printf("======= DELETE DATA =========\n");
                printf("\nData mahasiswa dengan npm keberapa yang ingin dihapus: ");
                scanf("%lld", &delKey); 
                mahasiswa = deleteData(mahasiswa, delKey);
                printf("Data mahasiswa dengan npm %lld berhasil dihapus.\n", delKey);
                system("pause");
                break;
            case 3:
                system("cls");
                printf("======================== MENAMPILKAN SEMUA DATA ========================\n");
                i = 1;
                printf("+------+--------------+-----------------+----------------------+--------+\n");
                printf("| No   | NPM          | Nama            | Prodi                | IPK    |\n");
                printf("+------+--------------+-----------------+----------------------+--------+\n");
                printData(mahasiswa, &i);
                printf("-------------------------------------------------------------------------\n");
                system("pause");
                break;
            case 4:
                system("cls");
                printf("======= SEARCHING DATA =========\n");
                printf("\nMasukkan NPM mahasiswa yang ingin dicari: ");
                scanf("%lld", &cari); 
                searching(mahasiswa, cari);
                system("pause");
                break;
            case 5:
                isRunning = 0;
                printf("Program berhenti....!!!\n");
                break;
            default:
                printf("Masukkan nomor dari program yang ingin dipilih...!!!\n");
                break;
        }
    }
}

mhs *newData(long long npm, char *nama, char *prodi, float ipk) {
    mhs *newMahasiswa = (mhs*) malloc(sizeof(mhs));
    newMahasiswa->npm = npm;
    strcpy(newMahasiswa->nama, nama);
    strcpy(newMahasiswa->prodi, prodi);
    newMahasiswa->ipk = ipk;
    newMahasiswa->left = NULL;
    newMahasiswa->right = NULL;
    return newMahasiswa;
}

mhs *insertData(mhs *mahasiswa, long long npm, char *nama, char *prodi, float ipk, int *status) {
    if (mahasiswa == NULL) {
        *status = 1;
        return newData(npm, nama, prodi, ipk);
    } else if (mahasiswa->npm == npm) {
        *status = 0;
        return mahasiswa;
    } else if (npm < mahasiswa->npm) {
        mahasiswa->left = insertData(mahasiswa->left, npm, nama, prodi, ipk, status);
    } else {
        mahasiswa->right = insertData(mahasiswa->right, npm, nama, prodi, ipk, status);
    }
    return mahasiswa;
}

mhs *deleteData(mhs *mahasiswa, long long npm) {
    if (mahasiswa == NULL) {
        printf("Data mahasiswa dengan npm %lld tidak ditemukan!!\n", npm);
        return NULL;
    }
    if (npm < mahasiswa->npm) {
        mahasiswa->left = deleteData(mahasiswa->left, npm);
    } else if (npm > mahasiswa->npm) {
        mahasiswa->right = deleteData(mahasiswa->right, npm);
    } else {
        if (mahasiswa->left == NULL) {
            mhs* temp = mahasiswa->right;
            free(mahasiswa);
            return temp;
        } else if (mahasiswa->right == NULL) {
            mhs* temp = mahasiswa->left;
            free(mahasiswa);
            return temp;
        }
        mhs* temp = predecessor(mahasiswa->left);
        mahasiswa->npm = temp->npm;
        strcpy(mahasiswa->nama, temp->nama);
        strcpy(mahasiswa->prodi, temp->prodi);
        mahasiswa->ipk = temp->ipk;
        mahasiswa->left = deleteData(mahasiswa->left, temp->npm);
    }
    return mahasiswa;
}

mhs *predecessor(mhs *mahasiswa) {
    while (mahasiswa->right != NULL) {
        mahasiswa = mahasiswa->right;
    }
    return mahasiswa;
}

void searching(mhs *mahasiswa, long long npm) {
    if (mahasiswa == NULL) {
        printf("\nData mahasiswa dengan npm %lld tidak ditemukan.\n", npm);
        return;
    }
    if (npm == mahasiswa->npm) {
        printf("\nData ditemukan dengan detail berikut:\n");
        printf("NPM: %lld\n", mahasiswa->npm);
        printf("Nama: %s\n", mahasiswa->nama);
        printf("Prodi: %s\n", mahasiswa->prodi);
        printf("IPK: %.2f\n", mahasiswa->ipk);
        return;
    } else if (npm < mahasiswa->npm) {
        searching(mahasiswa->left, npm);
    } else {
        searching(mahasiswa->right, npm);
    }
}

void printData(mhs *mahasiswa, int *i) {
    if (mahasiswa == NULL) return;

    printData(mahasiswa->left, i);
    printf("| %-4d | %-12lld | %-15s | %-20s | %-6.2f |\n", (*i)++, mahasiswa->npm, mahasiswa->nama, mahasiswa->prodi, mahasiswa->ipk);
    printData(mahasiswa->right, i);
}
