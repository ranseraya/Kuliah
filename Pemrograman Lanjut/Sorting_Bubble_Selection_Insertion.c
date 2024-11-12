#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mahasiswa{
    int NPM;
    char nama[50];
    char prodi[50];
    float IPK;
};

typedef struct mahasiswa Mahasiswa;

void tampilkanData(Mahasiswa mhs[], int jumlah);

void bubbleSortNPM(Mahasiswa mhs[], int jumlah, int arah);
void bubbleSortNama(Mahasiswa mhs[], int jumlah, int arah);
void bubbleSortIPK(Mahasiswa mhs[], int jumlah, int arah);

void selectionSortNPM(Mahasiswa mhs[], int jumlah, int arah);
void selectionSortNama(Mahasiswa mhs[], int jumlah, int arah);
void selectionSortIPK(Mahasiswa mhs[], int jumlah, int arah);

void insertionSortNPM(Mahasiswa mhs[], int jumlah, int arah);
void insertionSortNama(Mahasiswa mhs[], int jumlah, int arah);
void insertionSortIPK(Mahasiswa mhs[], int jumlah, int arah);

int main(){
    Mahasiswa mhs[] = {
        {123001, "Ayala", "Informatika", 4.00},
        {123002, "Sheryya", "Informatika", 3.84},
        {123003, "Ranse", "Informatika", 3.22},
        {123004, "Laya", "Informatika", 3.95},
        {123005, "Ahmad", "Informatika", 3.5},
        {123006, "Handa", "Informatika", 3.92},
        {123007, "Tama", "Informatika", 3.28},
        {123008, "Praga", "Informatika", 3.45},
        {123009, "Disya", "Informatika", 3.75},
        {123010, "Santia", "Informatika", 3.82},
        {123011, "Herta", "Informatika", 3.68},
        {123012, "Leswa", "Informatika", 2.88},
        {123013, "Matya", "Informatika", 3.12},
        {123014, "Tasya", "Informatika", 3.45},
        {123015, "Sulum", "Informatika", 3.5}
    };
    int pilihan, sorting, pilihanSort, arah;
    int jumlahMhs = sizeof(mhs)/sizeof(mhs[0]);
    while(1){
    printf("=== Program Bubble Sort Data ===\n");
    printf("1. Menampilkan data\n");
    printf("2. Sorting data\n");
    printf("3. Keluar program!\n");
    printf("Masukkan nomor program: ");
    scanf("%d", &pilihan);
    switch(pilihan){
        case 1:
            tampilkanData(mhs, jumlahMhs);
            break;
        case 2:
            printf("=== Pilih Jenis Sorting ===\n");
            printf("1. Bubble Sort\n");
            printf("2. Selection Sort\n");
            printf("3. Insertion Sort\n");
            printf("Pilih jenis sorting: ");
            scanf("%d", &sorting);
            switch(sorting){
                case 1:
                    printf("=== Arah pengurutan ===\n");
                    printf("1. Ascending(default)\n");
                    printf("2. Descending\n");
                    printf("Pilih nomor arah sorting: ");
                    scanf("%d", &arah);
                    printf("\n Pilih sorting berdasarkan\n");
                    printf("1. Berdasarkan NPM\n");
                    printf("2. Berdasarkan nama\n");
                    printf("3. Berdasarkan IPK\n");
                    printf("Masukkan nomor program: ");
                    scanf("%d", &pilihanSort);
                    switch(pilihanSort){
                        case 1:
                            bubbleSortNPM(mhs, jumlahMhs, arah);
                            break;
                        case 2:
                            bubbleSortNama(mhs, jumlahMhs, arah);
                            break;
                        case 3:
                            bubbleSortIPK(mhs, jumlahMhs, arah);
                            break;
                        default:
                            printf("Masukkan nomor dari program!! ");
                            break;
                    }
                    break;
                case 2:
                    printf("=== Arah pengurutan ===\n");
                    printf("1. Ascending(default)\n");
                    printf("2. Descending\n");
                    printf("Pilih nomor arah sorting: ");
                    scanf("%d", &arah);
                    printf("\n Pilih sorting berdasarkan\n");
                    printf("1. Berdasarkan NPM\n");
                    printf("2. Berdasarkan nama\n");
                    printf("3. Berdasarkan IPK\n");
                    printf("Masukkan nomor program: ");
                    scanf("%d", &pilihanSort);
                    switch(pilihanSort){
                        case 1:
                            selectionSortNPM(mhs, jumlahMhs, arah);
                            break;
                        case 2:
                            selectionSortNama(mhs, jumlahMhs, arah);
                            break;
                        case 3:
                            selectionSortIPK(mhs, jumlahMhs, arah);
                            break;
                        default:
                            printf("Masukkan nomor dari program!! ");
                            break;
                    }
                    break;
                case 3:
                    printf("=== Arah pengurutan ===\n");
                    printf("1. Ascending(default)\n");
                    printf("2. Descending\n");
                    printf("Pilih nomor arah sorting: ");
                    scanf("%d", &arah);
                    printf("\n Pilih sorting berdasarkan\n");
                    printf("1. Berdasarkan NPM\n");
                    printf("2. Berdasarkan nama\n");
                    printf("3. Berdasarkan IPK\n");
                    printf("Masukkan nomor program: ");
                    scanf("%d", &pilihanSort);
                    switch(pilihanSort){
                        case 1:
                            insertionSortNPM(mhs, jumlahMhs, arah);
                            break;
                        case 2:
                            insertionSortNama(mhs, jumlahMhs, arah);
                            break;
                        case 3:
                            insertionSortIPK(mhs, jumlahMhs, arah);
                            break;
                        default:
                            printf("Masukkan nomor dari program!! ");
                            break;
                    }
                    break;
                default:
                    printf("Masukkan nomor dari program!! ");
                    break;
            }
            break;
        case 3:
            printf("Program berhenti...!");
            return 0;
            break;
        default:
            printf("Masukkan nomor dari program!! ");
            break;
        }
    }
    return 0;
}

void tampilkanData(Mahasiswa mhs[], int jumlah){
        printf("|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
    for(int i = 0; i < jumlah; i++){
        printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", i+1, mhs[i].NPM, mhs[i].nama, mhs[i].prodi, mhs[i].IPK);
    }
}

void bubbleSortNPM(Mahasiswa mhs[], int jumlah, int arah){
    int perbandingan;
    for(int i = 0; i < jumlah-1; i++){
        for(int j = i+1; j < jumlah; j++){
            if(arah == 2){
                perbandingan = mhs[i].NPM < mhs[j].NPM;
            } else{
                perbandingan = mhs[i].NPM > mhs[j].NPM;
            }
            if(perbandingan){
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }
}

void bubbleSortNama(Mahasiswa mhs[], int jumlah, int arah){
    int perbandingan;
    for(int i = 0; i < jumlah-1; i++){
        for(int j = i+1; j < jumlah; j++){
                        if(arah == 2){
                perbandingan = strcmp(mhs[i].nama, mhs[j].nama);
            } else{
                perbandingan = strcmp(mhs[i].nama, mhs[j].nama);
            }
            perbandingan == -1 ? perbandingan = 0 : 1;
            if(perbandingan){
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }
}

void bubbleSortIPK(Mahasiswa mhs[], int jumlah, int arah){
    int perbandingan;
    for(int i = 0; i < jumlah-1; i++){
        for(int j = i+1; j < jumlah; j++){
            if(arah == 2){
                perbandingan = mhs[i].IPK < mhs[j].IPK;
            } else{
                perbandingan = mhs[i].IPK > mhs[j].IPK;
            }
            if(perbandingan){
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }
}

void selectionSortNPM(Mahasiswa mhs[], int jumlah, int arah){
    for(int i = 0; i < jumlah - 1; i++){
        int posisi = i;
        for(int j = i + 1; j < jumlah; j++){
            if(arah == 2){
                if(mhs[j].NPM > mhs[posisi].NPM){
                    posisi = j;
                }        
            } else 
                if(mhs[posisi].NPM > mhs[j].NPM){
                    posisi = j;
                }        
        }
        if(posisi != i){
            Mahasiswa temp = mhs[posisi];
            mhs[posisi] = mhs[i];
            mhs[i] = temp;
        }
    }
}

void selectionSortNama(Mahasiswa mhs[], int jumlah, int arah){
    for(int i = 0; i < jumlah - 1; i++){
        int posisi = i;
        for(int j = i + 1; j < jumlah; j++){
            if(arah == 2){
                if(strcmp(mhs[j].nama, mhs[posisi].nama) == 1){
                    posisi = j;
                }        
            } else 
                if(strcmp(mhs[posisi].nama, mhs[j].nama) == 1){
                    posisi = j;
                }        
        }
        if(posisi != i){
            Mahasiswa temp = mhs[posisi];
            mhs[posisi] = mhs[i];
            mhs[i] = temp;
        }
    }
}

void selectionSortIPK(Mahasiswa mhs[], int jumlah, int arah){
    for(int i = 0; i < jumlah - 1; i++){
        int posisi = i;
        for(int j = i + 1; j < jumlah; j++){
            if(arah == 2){
                if(mhs[j].IPK > mhs[posisi].IPK){
                    posisi = j;
                }        
            } else 
                if(mhs[posisi].IPK > mhs[j].IPK){
                    posisi = j;
                }        
        }
        if(posisi != i){
            Mahasiswa temp = mhs[posisi];
            mhs[posisi] = mhs[i];
            mhs[i] = temp;
        }
    }
}

void insertionSortNPM(Mahasiswa mhs[], int jumlah, int arah){
    int perbandingan;
    for(int i = 1; i < jumlah; i++){
        Mahasiswa temp = mhs[i];
        int j;
        for(j = i -1; j >= 0; j--){
            if(arah == 2){
                perbandingan = mhs[j].NPM < temp.NPM;
            }else {
                perbandingan = mhs[j].NPM > temp.NPM;
            }
            if(perbandingan){
                mhs[j + 1] = mhs[j];
            } else {
                break;
            }
        }
        mhs[j + 1] = temp;
    }
}

void insertionSortNama(Mahasiswa mhs[], int jumlah, int arah){
    int perbandingan;
    for(int i = 1; i < jumlah; i++){
        Mahasiswa temp = mhs[i];
        int j;
        for(j = i -1; j >= 0; j--){
            if(arah == 2){
                perbandingan = strcmp(mhs[j].nama, temp.nama) < 0;
            }else {
                perbandingan = strcmp(mhs[j].nama, temp.nama) > 0;
            }
            if(perbandingan){
                mhs[j + 1] = mhs[j];
            } else {
                break;
            }
        }
        mhs[j + 1] = temp;
    }
}

void insertionSortIPK(Mahasiswa mhs[], int jumlah, int arah){
    int perbandingan;
    for(int i = 1; i < jumlah; i++){
        Mahasiswa temp = mhs[i];
        int j;
        for(j = i -1; j >= 0; j--){
            if(arah == 2){
                perbandingan = mhs[j].IPK < temp.IPK;
            }else {
                perbandingan = mhs[j].IPK > temp.IPK;
            }
            if(perbandingan){
                mhs[j + 1] = mhs[j];
            } else {
                break;
            }
        }
        mhs[j + 1] = temp;
    }
}
