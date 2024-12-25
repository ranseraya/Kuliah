#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

MYSQL *conn;

struct penjadwalanProses{
    int waktuTiba;
    int burstTime;
    int priority;
    int height;
    struct penjadwalanProses* right;
    struct penjadwalanProses* left;
};
typedef struct penjadwalanProses proses;

void printData(proses *root, int *i);
int Max(int a, int b);
int getHeight(proses *root);
int getBalanceFactor(proses *root);
proses *newProses(int x, int y, int z);
proses *insertAVL(proses *root, int x, int y, int z, int *status);
proses *leftRotate(proses *x);
proses *rightRotate(proses *x);


proses *deleteAVL(proses *root, int z);
proses *successor(proses *root);
proses *predecessor(proses *root);
proses* balanceAVL(proses* root);
proses* rebalanceTree(proses* root);


void searchProses(proses *root, int cariPriority);

proses* insertBST(proses* root, int x, int y, int z, int *status);
proses* deleteBST(proses* root, int z);


void printTree(proses *root, int level);

void connectToDatabase();
proses* loadFromDatabase(proses *root);
proses* addNodeToAVL(proses* root, int x, int y, int z);

int main(){
    connectToDatabase();
    int i, metode, menu, status,jumlahProses, delKey, cari;

    proses *root = NULL;
    root = loadFromDatabase(root);

    while(1){
    printf("============ Program BST dan AVL =============\n");
    printf("===== Penjadwalan Proses CPU (priority) ======\n");
    printf("===== 1. BST\n");
    printf("===== 2. AVL\n");
    printf("===== 3. Keluar program\n");
    printf("===== Pilih nomor metode: ");
    scanf("%d", &metode);
    switch(metode){
        case 1:
            printf("===== Program BST ======\n");
            printf("1. Tambah Proses (Insert)\n");
            printf("2. Hapus Proses (Delete)\n");
            printf("3. Search Proses \n");
            printf("4. View \n");
            printf("5. Tampilkan Semua Data\n");
            printf("6. Kembali menu utama\n");
            printf("Pilih menu: ");
            scanf("%d", &menu);
            switch(menu){
                case 1:
                    printf("\nMasukkan jumlah proses: ");
                    scanf("%d", &jumlahProses);
                    for(int i = 1; i <= jumlahProses; i++){
                        int x = 0, y = 0, z = 0;
                        printf("Proses ke-%d:\n", i);
                        printf("Waktu tiba: ");
                        scanf("%d", &x);
                        printf("Burst Time: ");
                        scanf("%d", &y);
                        printf("Priority: ");
                        scanf("%d", &z);
                        root = insertBST(root, x, y, z, &status);
                        if (status == 0) {
                            printf("Priority %d sudah ada! Proses tidak ditambahkan.\n", z);
                        }
                    }
                    break;
                case 2:
                    printf("\n");
                    printf("Proses dengan prioritas keberapa yang ingin dihapus: ");
                    scanf("%d", &delKey);
                    deleteBST(root, delKey);
                    break;
                case 3:
                    printf("\n");
                    printf("Masukkan prioritas data yang ingin dicari: ");
                    scanf("%d", &cari);
                    searchProses(root, cari);
                    break;
                case 4:
                    // printData(root);
                    printf("\n");
                    printTree(root, 0); 
                    printf("\n");
                    break;
                case 5:
                    i = 1;
                    printf("+------+--------------+--------------+------------+\n");
                    printf("| No   | Waktu Tiba   | Burst Time   | Priority   |\n");
                    printf("+------+--------------+--------------+------------+\n");
                    printData(root, &i);
                    printf("---------------------------------------------------\n");
                    break;
                case 6:
                    break;
                default:
                    printf("Masukkan nomor dari program(ex: 1)!!\n");
                    break;
            }
            break;
        case 2:
            printf("===== Program AVL ======\n");
            printf("1. Tambah Proses (Insert)\n");
            printf("2. Hapus Proses (Delete)\n");
            printf("3. Search Proses \n");
            printf("4. View \n");
            printf("5. Balance AVL\n");
            printf("6. Tampilkan Semua Data\n");
            printf("7. Kembali menu utama\n");
            printf("Pilih menu: ");
            scanf("%d", &menu);
            switch(menu){
                case 1:
                    printf("\nMasukkan jumlah proses: ");
                    scanf("%d", &jumlahProses);
                    for(int i = 1; i <= jumlahProses; i++){
                        int x = 0, y = 0, z = 0;
                        printf("Proses ke-%d:\n", i);
                        printf("Waktu tiba: ");
                        scanf("%d", &x);
                        printf("Burst Time: ");
                        scanf("%d", &y);
                        printf("Priority: ");
                        scanf("%d", &z);
                        root = insertAVL(root, x, y, z, &status);
                        if (status == 0) {
                            printf("Priority %d sudah ada! Proses tidak ditambahkan.\n", z);
                        }
                    }
                    break;
                case 2:
                    printf("\n");
                    printf("Proses dengan prioritas keberapa yang ingin dihapus: ");
                    scanf("%d", &delKey);
                    deleteAVL(root, delKey);
                    break;
                case 3:
                    printf("\n");
                    printf("Masukkan prioritas data yang ingin dicari: ");
                    scanf("%d", &cari);
                    searchProses(root, cari);
                    break;
                case 4:
                    printf("\n");
                    printTree(root, 0);
                    printf("\n");
                    break;
                case 5:
                    root = rebalanceTree(root);
                    printf("\nData tree telah diseimbangkan..!!\n");
                    break;;
                case 6:
                    i = 1;
                    printf("+------+--------------+--------------+------------+\n");
                    printf("| No   | Waktu Tiba   | Burst Time   | Priority   |\n");
                    printf("+------+--------------+--------------+------------+\n");
                    printData(root, &i);
                    printf("---------------------------------------------------\n");
                    break;
                case 7:
                    break;
                default:
                    printf("Masukkan nomor dari program(ex: 1)!!\n");
                    break;
            }
            break;
        case 3:
            printf("Program berhenti....!!!\n");
            return 0;
        default:
            printf("Masukkan nomor dari program(ex: 1)!!\n");
            break;
    }
    printf("\n");
    }
    mysql_close(conn);
    return 0;
}

void printData(proses *root, int *i){
    if (root == NULL) {
        return; 
    }

    printData(root->left, i);
    printf("| %-4d | %-12d | %-12d | %-10d |\n", (*i)++, root->waktuTiba, root->burstTime, root->priority);

    printData(root->right, i);
}

int Max(int a, int b){
    if(a > b) return a;
    return b;
}

int getHeight(proses *root){
    if(root == NULL)return 0;
    return root->height;
}

int getBalanceFactor(proses *root){
    // -1 0 1
    if(root == NULL)return 0;
    return getHeight(root->left) - getHeight(root->right);
}

proses *newProses(int x, int y, int z){
    proses *newCurProses = (proses*) malloc(sizeof(proses));
    newCurProses->waktuTiba = x;
    newCurProses->burstTime = y;
    newCurProses->priority = z;
    newCurProses->left = NULL;
    newCurProses->right = NULL;
    newCurProses->height = 1;
    return newCurProses;
}


proses *insertAVL(proses *root, int x, int y, int z, int *status) {
    if (root == NULL) {
        *status = 1; 
        proses *newNode = newProses(x, y, z);
        if (*status == 1) {
            char query[256];
            snprintf(query, sizeof(query),
                     "INSERT INTO proses (waktu_tiba, burst_time, priority) VALUES (%d, %d, %d)",
                     x, y, z);

            if (mysql_query(conn, query)) {
                fprintf(stderr, "Gagal menyimpan data ke database: %s\n", mysql_error(conn));
            } else {
                printf("Data dengan priority %d berhasil disimpan ke database.\n", z);
            }
        }
        return newNode;
    } else if (root->priority == z) {
        *status = 0; 
        return root;
    } else if (root->priority < z) {
        root->right = insertAVL(root->right, x, y, z, status);
    } else {
        root->left = insertAVL(root->left, x, y, z, status);
    }
    return balanceAVL(root);
}

proses *leftRotate(proses *x){
    proses *y = x->right;
    proses *z = y->left;


    // rotate
    y->left = x;
    x->right = z;

    x->height = Max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = Max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

proses *rightRotate(proses *x){
    proses *y = x->left;
    proses *z = y->right;


    // rotate
    y->right = x;
    x->left = z;

    x->height = Max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = Max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

proses *deleteAVL(proses *root, int z){
    if(root == NULL){
        printf("Proses dengan priority %d tidak ditemukan.\n", z);
        return NULL;
    } else if(root->priority < z){
        root->right = deleteAVL(root->right, z);
    } else if(root->priority > z){
        root->left = deleteAVL(root->left, z);
    } else{
        char query[256];
        snprintf(query, sizeof(query), "DELETE FROM proses WHERE priority = %d", z);
        if (mysql_query(conn, query)) {
            fprintf(stderr, "Gagal menghapus data dari database: %s\n", mysql_error(conn));
        } else {
            printf("Data dengan priority %d berhasil dihapus dari database.\n", z);
        }
        if(root->left == NULL || root->right == NULL){
            proses *temp = NULL;
            if(root->left == NULL){
                temp = root->right;
            } else{
                temp = root->left;
            }
            if(temp == NULL){
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        }else{
            proses *temp = predecessor(root->left);
            root->priority = temp->priority;
            root->waktuTiba = temp->waktuTiba;
            root->burstTime = temp->burstTime;

            root->left = deleteAVL(root->left, temp->priority);
        }
    }
    if(root == NULL) return root;
    return balanceAVL(root);
}

proses *predecessor(proses *root){
    proses *cur = root;
    while(cur->right != NULL){
        cur = cur->right;
    }
    return cur;
}

proses *successor(proses *root){
    proses *cur = root;
    while(cur->left != NULL){
        cur = cur->left;
    }
    return cur;
}

proses* balanceAVL(proses* root) {
    //Pengecekan height
    root->height = Max(getHeight(root->left), getHeight(root->right))+1;
    //Pengecekan Balancing / balancing
    int bFactor = getBalanceFactor(root);

    if(bFactor > 1 && getBalanceFactor(root->left) > 0){
        //right rotate
        return rightRotate(root);
    }else if(bFactor > 1 && getBalanceFactor(root->left) <= 0){
        // left rotate child
        root->left = leftRotate(root->left); 
        // right rotate
        return rightRotate(root);
    }else if(bFactor < -1 && getBalanceFactor(root->right) <= 0){
        // left rotate
        return leftRotate(root);
    }else if(bFactor < -1 && getBalanceFactor(root->right) > 0){
        // right rotate child
        root->right = rightRotate(root->right);
        // left rotate
        return leftRotate(root);
    }
    return root;
}

proses* rebalanceTree(proses* root) {
    if (root == NULL) return NULL;

    root->left = rebalanceTree(root->left);
    root->right = rebalanceTree(root->right);

    return balanceAVL(root);
}

void searchProses(proses *root, int cariPriority) {
    if (root == NULL) {
        printf("\nData dengan prioritas %d tidak ditemukan.\n", cariPriority);
        return;
    }

    if (cariPriority == root->priority) {
        printf("\nData ditemukan dengan detail berikut:\n");
        printf("Waktu Tiba: %d\n", root->waktuTiba);
        printf("Burst Time: %d\n", root->burstTime);
        printf("Priority: %d\n", root->priority);
        return;
    } else if (cariPriority < root->priority) {
        searchProses(root->left, cariPriority);
    } else {
        searchProses(root->right, cariPriority);
    }
}

proses *insertBST(proses *root, int x, int y, int z, int *status) {
    if (root == NULL) {
        *status = 1; 
        proses *newNode = newProses(x, y, z);
        if (*status == 1) {
            char query[256];
            snprintf(query, sizeof(query),
                     "INSERT INTO proses (waktu_tiba, burst_time, priority) VALUES (%d, %d, %d)",
                     x, y, z);

            if (mysql_query(conn, query)) {
                fprintf(stderr, "Gagal menyimpan data ke database: %s\n", mysql_error(conn));
            } else {
                printf("Data dengan priority %d berhasil disimpan ke database.\n", z);
            }
        }
        return newNode;
    } else if (root->priority == z) {
        *status = 0; 
        return root;
    } else if (root->priority < z) {
        root->right = insertBST(root->right, x, y, z, status);
    } else {
        root->left = insertBST(root->left, x, y, z, status);
    }
    // Pada BST tidak ada penanganan balancing seperti AVL
    return root;
}

proses* deleteBST(proses* root, int z) {
    if (root == NULL) {
        printf("Proses dengan priority %d tidak ditemukan.\n", z);
        return NULL;
    }
    if (z < root->priority) {
        root->left = deleteBST(root->left, z);
    } else if (z > root->priority) {
        root->right = deleteBST(root->right, z);
    } else {

        char query[256];
        snprintf(query, sizeof(query), "DELETE FROM proses WHERE priority = %d", z);

        if (mysql_query(conn, query)) {
            fprintf(stderr, "Gagal menghapus data dari database: %s\n", mysql_error(conn));
        } else {
            printf("Data dengan priority %d berhasil dihapus dari database.\n", z);
        }

        if (root->left == NULL) {
            proses* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            proses* temp = root->left;
            free(root);
            return temp;
        }
        // Node dengan dua anak: ambil successor (kiri paling kanan)
        proses* temp = predecessor(root->left);
        root->priority = temp->priority;
        root->waktuTiba = temp->waktuTiba;
        root->burstTime = temp->burstTime;
        root->left = deleteBST(root->left, temp->priority);
    }
    return root;
}


void printTree(proses *root, int level) {
    if (root == NULL) return;
    printTree(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("   ");
    }


    printf("%d\n", root->priority);

    printTree(root->left, level + 1);
}


void connectToDatabase() {
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "ayala", "projek_akhir_strukdat", 3306, NULL, 0)) { 
        fprintf(stderr, "Koneksi gagal: %s\n", mysql_error(conn));
        exit(1);
    }
}


proses* loadFromDatabase(proses *root) {
    if (mysql_query(conn, "SELECT waktu_tiba, burst_time, priority FROM proses")) {
        fprintf(stderr, "Gagal memuat data dari database: %s\n", mysql_error(conn));
        return root;
    }

    MYSQL_RES *res = mysql_store_result(conn);
    if (res == NULL) {
        fprintf(stderr, "Gagal menyimpan hasil query: %s\n", mysql_error(conn));
        return root;
    }

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {
        int waktuTiba = atoi(row[0]);
        int burstTime = atoi(row[1]);
        int priority = atoi(row[2]);

        int status;
        root = addNodeToAVL(root, waktuTiba, burstTime, priority);
    }

    mysql_free_result(res);
    printf("Data berhasil dimuat dari database.\n");
    return root;
}

proses* addNodeToAVL(proses* root, int x, int y, int z) {
    if (root == NULL) {
        proses* newNode = (proses*)malloc(sizeof(proses));
        newNode->waktuTiba = x;
        newNode->burstTime = y;
        newNode->priority = z;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1; 
        return newNode;
    }

    if (z < root->priority) {
        root->left = addNodeToAVL(root->left, x, y, z);
    } else if (z > root->priority) {
        root->right = addNodeToAVL(root->right, x, y, z);
    }

    return balanceAVL(root);
}




