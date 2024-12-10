#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

void merge(Mahasiswa mhs[], int left, int mid, int right, int pilihanSort, int arah);
void mergeSort(Mahasiswa mhs[], int left, int right, int pilihanSort, int arah);

void sequentialSearch(Mahasiswa mhs[], int jumlah, char cari[], int pilihanSearch);
void sentinelSearch(Mahasiswa mhs[], int jumlah, char cari[], int pilihanSearch);
void binarySearch(Mahasiswa mhs[], int jumlah, char cari[], int pilihanSearch);
void interpolationSearch(Mahasiswa mhs[], int jumlah, char cari[], int pilihanSearch);
void jumpSearch(Mahasiswa mhs[], int jumlah, char cari[], int pilihanSearch);


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
        {123015, "Sulum", "Informatika", 3.5},
        {123016, "Septa", "Informatika", 4.00},
        {123017, "Rahan", "Informatika", 3.75},
        {123018, "Iwas", "Informatika", 3.92},
        {123019, "Larya", "Informatika", 3.21},
        {123020, "Tepda", "Informatika", 2.96},
        {123021, "Dany", "Informatika", 4.00},
        {123022, "Nadra", "Informatika", 3.45},
        {123023, "Pitha", "Informatika", 3.32},
        {123024, "Andre", "Informatika", 3.92},
        {123025, "Alran", "Informatika", 3.32},
        {123026, "Mada", "Informatika", 3.5},
        {123027, "Nery", "Informatika", 3.88},
        {123028, "Lamse", "Informatika", 3.42},
        {123029, "Damda", "Informatika", 4.00},
        {123030, "Lili", "Informatika", 3.5}
    };
    int pilihan, sorting, pilihanSort, arah, searching, pilihanSearch;
    char cari[100];
    int jumlahMhs = sizeof(mhs)/sizeof(mhs[0]);
    while(1){
    printf("=== Program Bubble Sort Data ===\n");
    printf("1. Menampilkan data\n");
    printf("2. Sorting data\n");
    printf("3. Search data\n");
    printf("4. Keluar program!\n");
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
            printf("4. Merge Sort\n");
            printf("Pilih jenis sorting: ");
            scanf("%d", &sorting);
            switch(sorting){
                case 1:
                    printf("=== Arah pengurutan ===\n");
                    printf("1. Ascending(default)\n");
                    printf("2. Descending\n");
                    printf("Pilih nomor arah sorting: ");
                    scanf("%d", &arah);
                    printf("\nPilih sorting berdasarkan\n");
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
                    printf("\nPilih sorting berdasarkan\n");
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
                    printf("\nPilih sorting berdasarkan\n");
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
                case 4:
                    printf("=== Arah pengurutan ===\n");
                    printf("1. Ascending(default)\n");
                    printf("2. Descending\n");
                    printf("Pilih nomor arah sorting: ");
                    scanf("%d", &arah);
                    printf("\nPilih sorting berdasarkan\n");
                    printf("1. Berdasarkan NPM\n");
                    printf("2. Berdasarkan nama\n");
                    printf("3. Berdasarkan IPK\n");
                    printf("Masukkan nomor program: ");
                    scanf("%d", &pilihanSort);
                    switch(pilihanSort){
                        case 1:
                            mergeSort(mhs, 0, jumlahMhs-1, 1, arah);
                            break;
                        case 2:
                            mergeSort(mhs, 0, jumlahMhs-1, 2, arah);
                            break;
                        case 3:
                            mergeSort(mhs, 0, jumlahMhs-1, 3, arah);
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
            printf("=== Pilih Jenis Pencarian ===\n");
            printf("1. Sequential Search\n");
            printf("2. Sentinel search\n");
            printf("3. Binary Search\n");
            printf("4. Interpolation Search\n");
            printf("5. Jump Search\n");
            printf("Pilih jenis searching: ");
            scanf("%d", &searching);
            switch(searching){
                case 1:
                    printf("\nPilih searching berdasarkan\n");
                    printf("1. Berdasarkan NPM\n");
                    printf("2. Berdasarkan nama\n");
                    printf("3. Berdasarkan IPK\n");
                    printf("4. Berdasarkan Keseluruhan\n");
                    printf("Masukkan nomor program: ");
                    scanf("%d", &pilihanSearch);
                    printf("Masukkan kata kunci pencarian: ");
                    scanf("%s", &cari);
                    switch(pilihanSearch){
                        case 1:
                            sequentialSearch(mhs, jumlahMhs, cari, 1);
                            break;
                        case 2:
                            sequentialSearch(mhs, jumlahMhs, cari, 2);
                            break;
                        case 3:
                            sequentialSearch(mhs, jumlahMhs, cari, 3);
                            break;
                        case 4:
                            sequentialSearch(mhs, jumlahMhs, cari, 4);
                            break;
                        default:
                            printf("Masukkan nomor dari program!! ");
                            break;
                    }
                    break;
                case 2:
                    printf("\nPilih searching berdasarkan\n");
                    printf("1. Berdasarkan NPM\n");
                    printf("2. Berdasarkan nama\n");
                    printf("3. Berdasarkan IPK\n");
                    printf("4. Berdasarkan Keseluruhan\n");
                    printf("Masukkan nomor program: ");
                    scanf("%d", &pilihanSearch);
                    printf("Masukkan kata kunci pencarian: ");
                    scanf("%s", &cari);
                    switch(pilihanSearch){
                        case 1:
                            sentinelSearch(mhs, jumlahMhs, cari, 1);
                            break;
                        case 2:
                            sentinelSearch(mhs, jumlahMhs, cari, 2);
                            break;
                        case 3:
                            sentinelSearch(mhs, jumlahMhs, cari, 3);
                            break;
                        case 4:
                            sentinelSearch(mhs, jumlahMhs, cari, 4);
                            break;
                        default:
                            printf("Masukkan nomor dari program!! ");
                            break;
                    }
                    break;
                case 3:
                    printf("\nPilih searching berdasarkan\n");
                    printf("1. Berdasarkan NPM\n");
                    printf("2. Berdasarkan nama\n");
                    printf("3. Berdasarkan IPK\n");
                    printf("Masukkan nomor program: ");
                    scanf("%d", &pilihanSearch);
                    printf("Masukkan kata kunci pencarian: ");
                    scanf("%s", &cari);
                    switch(pilihanSearch){
                        case 1:
                            binarySearch(mhs, jumlahMhs, cari, 1);
                            break;
                        case 2:
                            binarySearch(mhs, jumlahMhs, cari, 2);
                            break;
                        case 3:
                            binarySearch(mhs, jumlahMhs, cari, 3);
                            break;
                        default:
                            printf("Masukkan nomor dari program!! ");
                            break;
                    }
                    break;
                case 4:
                    printf("\nPilih searching berdasarkan\n");
                    printf("1. Berdasarkan NPM\n");
                    printf("2. Berdasarkan nama\n");
                    printf("3. Berdasarkan IPK\n");
                    printf("Masukkan nomor program: ");
                    scanf("%d", &pilihanSearch);
                    printf("Masukkan kata kunci pencarian: ");
                    scanf("%s", &cari);
                    switch(pilihanSearch){
                        case 1:
                            interpolationSearch(mhs, jumlahMhs, cari, 1);
                            break;
                        case 2:
                            interpolationSearch(mhs, jumlahMhs, cari, 2);
                            break;
                        case 3:
                            interpolationSearch(mhs, jumlahMhs, cari, 3);
                            break;
                        default:
                            printf("Masukkan nomor dari program!! ");
                            break;
                    }
                    break;
                case 5:
                    printf("\nPilih searching berdasarkan\n");
                    printf("1. Berdasarkan NPM\n");
                    printf("2. Berdasarkan nama\n");
                    printf("3. Berdasarkan IPK\n");
                    printf("Masukkan nomor program: ");
                    scanf("%d", &pilihanSearch);
                    printf("Masukkan kata kunci pencarian: ");
                    scanf("%s", &cari);
                    switch(pilihanSearch){
                        case 1:
                            jumpSearch(mhs, jumlahMhs, cari, 1);
                            break;
                        case 2:
                            jumpSearch(mhs, jumlahMhs, cari, 2);
                            break;
                        case 3:
                            jumpSearch(mhs, jumlahMhs, cari, 3);
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
        case 4:
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

void merge(Mahasiswa mhs[], int left, int mid, int right, int pilihanSort, int arah){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Mahasiswa L[n1], R[n2];

    for(int i = 0; i < n1; i++){
        L[i] = mhs[left + i];
    }
    for(int j = 0; j < n2;j++){
        R[j] = mhs[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        int perbandingan;
        if(pilihanSort == 1){
            perbandingan = (arah == 1) ? L[i].NPM <= R[j].NPM : L[i].NPM >= R[j].NPM;
        } else if(pilihanSort == 2){
            perbandingan = (arah == 1) ? (strcmp(L[i].nama, R[j].nama) <= 0) : (strcmp(L[i].nama, R[j].nama) >= 0);
        } else if(pilihanSort == 3){
            perbandingan = (arah == 1) ? L[i].IPK <= R[j].IPK : L[i].IPK >= R[j].IPK;
        }else {
            printf("Masukkan nomor dari program!...");
            break;
        }
        if(perbandingan){
            mhs[k] = L[i];
            i++;
        }else{
            mhs[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        mhs[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        mhs[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Mahasiswa mhs[], int left, int right, int pilihanSort, int arah){
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(mhs, left, mid, pilihanSort, arah);
        mergeSort(mhs, mid + 1, right, pilihanSort, arah);

        merge(mhs, left, mid, right, pilihanSort, arah);
    }
}

void sequentialSearch(Mahasiswa mhs[], int jumlah, char cari[], int pilihanSearch){
    int flag = 0;
    for(int i = 0; i < jumlah; i++){
        char npmString[10], ipkString[5];
        sprintf(npmString, "%d", mhs[i].NPM);
        sprintf(ipkString, "%.2f", mhs[i].IPK);
        if(pilihanSearch == 1){
            // if(npmString == cari){
            if(strncmp(npmString, cari, strlen(cari)) == 0){
                if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
                flag = 1;
                printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", i+1, mhs[i].NPM, mhs[i].nama, mhs[i].prodi, mhs[i].IPK);
            }
        } else if (pilihanSearch == 2){
            if(strncmp(mhs[i].nama, cari, strlen(cari)) == 0){
                if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
                flag = 1;
                printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", i+1, mhs[i].NPM, mhs[i].nama, mhs[i].prodi, mhs[i].IPK);

            } 
        } else if (pilihanSearch == 3){
            if(strncmp(ipkString, cari, strlen(cari)) == 0){
                if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
                flag = 1;
                printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", i+1, mhs[i].NPM, mhs[i].nama, mhs[i].prodi, mhs[i].IPK);
            }
        } else if (pilihanSearch == 4){
            if(strncmp(npmString, cari, strlen(cari)) == 0 || strncmp(mhs[i].nama, cari, strlen(cari)) == 0|| strncmp(ipkString, cari, strlen(cari)) == 0){
                if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
                flag = 1;
                printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", i+1, mhs[i].NPM, mhs[i].nama, mhs[i].prodi, mhs[i].IPK);
            }
        } 
    }
    if(flag == 0){
        printf("\nData tidak ada");
    }
    printf("\n");
}

void sentinelSearch(Mahasiswa mhs[], int jumlah, char cari[], int pilihanSearch){
    int flag = 0;
    int cariNPM = atoi(cari);  
    float cariIPK = atof(cari); 

    Mahasiswa sentinel;
    sentinel.NPM = cariNPM;
    strncpy(sentinel.nama, cari, sizeof(sentinel.nama) - 1);
    sentinel.nama[sizeof(sentinel.nama) - 1] = '\0';  
    sentinel.IPK = cariIPK;

    int i = 0;
    while (1) {
    char npmString[10], ipkString[5];
    sprintf(npmString, "%d", mhs[i].NPM);
    strlen(cari) == 3 ? sprintf(ipkString, "%.1f", mhs[i].IPK) : sprintf(ipkString, "%.2f", mhs[i].IPK);

        if(pilihanSearch == 1) {
            if(strncmp(npmString, cari, strlen(cari)) == 0) {
                if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
                flag = 1;
                printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", i+1, mhs[i].NPM, mhs[i].nama, mhs[i].prodi, mhs[i].IPK);
            }
        } else if (pilihanSearch == 2) {
            if(strncmp(mhs[i].nama, cari, strlen(cari)) == 0) {
                if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
                flag = 1;
                printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", i+1, mhs[i].NPM, mhs[i].nama, mhs[i].prodi, mhs[i].IPK);
            }
        } else if (pilihanSearch == 3) {
            if(strncmp(ipkString, cari, strlen(cari)) == 0) {
                if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
                flag = 1;
                printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", i+1, mhs[i].NPM, mhs[i].nama, mhs[i].prodi, mhs[i].IPK);
            }
        } else if (pilihanSearch == 4) {
            if(mhs[i].NPM == cariNPM || strncmp(mhs[i].nama, cari, strlen(cari)) == 0 || mhs[i].IPK == cariIPK) {
                if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
                flag = 1;
                printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", i+1, mhs[i].NPM, mhs[i].nama, mhs[i].prodi, mhs[i].IPK);
            }
        }
        i++; 
        if (i > jumlah - 1) {
            break;
        }
    }

    if(flag == 0) {
        printf("\nData tidak ada");
    }
    printf("\n");
}


void binarySearch(Mahasiswa mhs[], int jumlah, char cari[], int pilihanSearch){
    mergeSort(mhs, 0, jumlah-1, pilihanSearch, 1);
    int flag = 0, left = 0, right = jumlah - 1, mid, perbandingan;

    while(left <= right){
        mid = (left + right)/2;
        char npmString[10], ipkString[5];
        if(pilihanSearch == 1){
            sprintf(npmString, "%d", mhs[mid].NPM);
            perbandingan = strcmp(npmString, cari);
        } else if (pilihanSearch == 2){
            perbandingan = strcmp(mhs[mid].nama, cari);
        } else if (pilihanSearch == 3){
            strlen(cari) == 3 ? sprintf(ipkString, "%.1f", mhs[mid].IPK) : sprintf(ipkString, "%.2f", mhs[mid].IPK);
            perbandingan = strcmp(ipkString, cari);
        } else{
            printf("Masukkan nomor program...!");
        }
        if(perbandingan == 0){
            if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
            flag = 1;
            printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", mid+1, mhs[mid].NPM, mhs[mid].nama, mhs[mid].prodi, mhs[mid].IPK);
            break;
        } else if (perbandingan < 0){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if(flag == 0){
        printf("\nData tidak ada");
    }
    printf("\n");
}


void interpolationSearch(Mahasiswa mhs[], int jumlah, char cari[], int pilihanSearch){
    mergeSort(mhs, 0, jumlah-1, pilihanSearch, 1);
    int flag = 0, left = 0, right = jumlah - 1, pos, perbandingan;
    char npmString[10], ipkString[5];

    while(left <= right && flag == 0){
        if(pilihanSearch == 1){
            int cariInt = atoi(cari); 
            if (mhs[left].NPM == mhs[right].NPM) {
                pos = left; 
            } else {
                pos = left + ((double)(right - left) / 
                             (mhs[right].NPM - mhs[left].NPM)) * 
                             (cariInt - mhs[left].NPM);
            }
            sprintf(npmString, "%d", mhs[pos].NPM);
            perbandingan = strcmp(npmString, cari);
        } else if (pilihanSearch == 2){
            pos = left + ((double)(right - left) / 
                         (strcmp(mhs[right].nama, mhs[left].nama))) * 
                         strcmp(cari, mhs[left].nama);
            perbandingan = strcmp(mhs[pos].nama, cari);
        } else if (pilihanSearch == 3){
            double cariDouble = atof(cari); 
            if (mhs[left].IPK == mhs[right].IPK) {
                pos = left; 
            } else {
                pos = left + ((double)(right - left) / 
                             (mhs[right].IPK - mhs[left].IPK)) * 
                             (cariDouble - mhs[left].IPK);
            }
            strlen(cari) == 3 ? sprintf(ipkString, "%.1f", mhs[pos].IPK) : sprintf(ipkString, "%.2f", mhs[pos].IPK);
            perbandingan = strcmp(ipkString, cari);
        }

        if (pos < left || pos > right) break;

        if(perbandingan == 0){
            if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
            flag = 1;
            printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", pos+1, mhs[pos].NPM, mhs[pos].nama, mhs[pos].prodi, mhs[pos].IPK);
            break;
        } else if (perbandingan < 0){
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    if(flag == 0){
        printf("\nData tidak ada");
    }
    printf("\n");
}


void jumpSearch(Mahasiswa mhs[], int jumlah, char cari[], int pilihanSearch) {
    mergeSort(mhs, 0, jumlah-1, pilihanSearch, 1);
    int lompatan = sqrt(jumlah); 
    int prev = 0, current = 0, flag = 0;
    int perbandingan;
    char npmString[10], ipkString[5];

    while (current < jumlah) {
        if (pilihanSearch == 1) {
            sprintf(npmString, "%d", mhs[current].NPM);
            if (strcmp(npmString, cari) >= 0) break;
        } else if (pilihanSearch == 2) {
            if (strcmp(mhs[current].nama, cari) >= 0) break;
        } else if (pilihanSearch == 3) {
            strlen(cari) == 3 ? sprintf(ipkString, "%.1f", mhs[current].IPK) : sprintf(ipkString, "%.2f", mhs[current].IPK);
            if (strcmp(ipkString, cari) >= 0) break;
        }
        prev = current;
        current += lompatan;
        if (current >= jumlah) current = jumlah - 1;
    }

    for (int i = prev; i <= current && i < jumlah; i++) {
        if (pilihanSearch == 1) {
            sprintf(npmString, "%d", mhs[i].NPM);
            perbandingan = strcmp(npmString, cari);
        } else if (pilihanSearch == 2) {
            perbandingan = strcmp(mhs[i].nama, cari);
        } else if (pilihanSearch == 3) {
            strlen(cari) == 3 ? sprintf(ipkString, "%.1f", mhs[i].IPK) : sprintf(ipkString, "%.2f", mhs[i].IPK);
            perbandingan = strcmp(ipkString, cari);
        } else {
            printf("Masukkan nomor prorgam...!\n");
            return;
        }

        if (perbandingan == 0) {
            if (flag != 1) printf("\nData ditemukan berikut detailnya: \n|%-3s|%-6s|%-10s|%-13s|%-4s|\n", "No.","NPM","Nama","Prodi", "IPK");
            flag = 1;
            printf("|%-3d|%-6d|%-10s|%-13s|%-4.2f|\n", i + 1, mhs[i].NPM, mhs[i].nama, mhs[i].prodi, mhs[i].IPK);
        }
    }

    if (flag == 0) {
        printf("\nData tidak ditemukan.\n");
    }
    printf("\n");
}
