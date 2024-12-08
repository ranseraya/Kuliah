#include <stdio.h>
#include <stdlib.h>

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
proses *insertAVL(proses *root, int x, int y, int z);
proses *leftRotate(proses *x);
proses *rightRotate(proses *x);


proses *deleteAVL(proses *root, int z);
proses *successor(proses *root);
proses *predecessor(proses *root);
proses* balanceAVL(proses* root);
proses* rebalanceTree(proses* root);


void searchProses(proses *root, int cariPriority);

proses* insertBST(proses* root, int x, int y, int z);
proses* deleteBST(proses* root, int z);


void printTree(proses *root, int level);

int main(){
    int i, metode, menu, jumlahProses, delKey, cari;

    proses *root = NULL;

    root = insertAVL(root, 0, 3, 4);
    root = insertAVL(root, 3, 2, 2);
    root = insertAVL(root, 7, 5, 5);
    root = insertAVL(root, 14, 6, 1);
    root = insertAVL(root, 10, 2, 6);
    root = insertAVL(root, 14, 4, 9);
    root = insertAVL(root, 16, 2, 3);


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
                    printf("\n");
                    printf("Masukkan jumlah proses: ");
                    scanf("%d", &jumlahProses);
                    for(int i = 0; i < jumlahProses; i++){
                        int x = 0, y = 0, z = 0;
                        printf("Waktu tiba: ");
                        scanf("%d", &x);
                        printf("BurstTime: ");
                        scanf("%d", &y);
                        printf("Priority: ");
                        scanf("%d", &z);
                        root = insertBST(root, x, y, z);
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
                    printf("\n");
                    printf("Masukkan jumlah proses: ");
                    scanf("%d", &jumlahProses);
                    for(int i = 0; i < jumlahProses; i++){
                        int x = 0, y = 0, z = 0;
                        printf("Waktu tiba: ");
                        scanf("%d", &x);
                        printf("BurstTime: ");
                        scanf("%d", &y);
                        printf("Priority: ");
                        scanf("%d", &z);
                        root = insertAVL(root, x, y, z);
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
                    // printData(root);
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

proses *insertAVL(proses *root, int x, int y, int z){
    if(root == NULL){
        return newProses(x, y, z);
    } else if(root->priority < z){
        root->right = insertAVL(root->right, x, y, z);
    } else {
        root->left = insertAVL(root->left, x, y, z);
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
        return NULL;
    } else if(root->priority < z){
        root->right = deleteAVL(root->right, z);
    } else if(root->priority > z){
        root->left = deleteAVL(root->left, z);
    } else{

        if(root->left == NULL || root->right == NULL){
            proses *temp = NULL;
            if(root->left == NULL){
                temp = root->right;
            } else{
                temp = root->left;
            }

            if(temp == NULL){
                // case 1 tidak memiliki child
                temp = root;
                root = NULL;
            } else {
                // case 2 hanya ada child kiri
                // case 3 hanya ada child kanan
                *root = *temp;
            }
            free(temp);
        }else{
            // case 4 ada 2 child
            //ambil predecessor(node akhir child kiri) atau successor(node akhir child kanan)
            proses *temp = predecessor(root->left);
            root->priority = temp->priority;

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

proses* insertBST(proses* root, int x, int y, int z) {
    if (root == NULL) {
        return newProses(x, y, z);
    }
    if (z < root->priority) {
        root->left = insertBST(root->left, x, y, z);
    } else if (z > root->priority) {
        root->right = insertBST(root->right, x, y, z);
    }

    // Pada BST tidak ada penanganan balancing seperti AVL
    return root; 
}

proses* deleteBST(proses* root, int z) {
    if (root == NULL) {
        return root;
    }
    if (z < root->priority) {
        root->left = deleteBST(root->left, z);
    } else if (z > root->priority) {
        root->right = deleteBST(root->right, z);
    } else {
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
        root->left = deleteBST(root->left, temp->priority);
    }
    return root;
}


void printTree(proses *root, int level) {
    if (root == NULL) return;
    // Cetak subtree kanan terlebih dahulu agar pohon mirip bentuk visual
    printTree(root->right, level + 1);

    // Cetak indentasi sesuai level
    for (int i = 0; i < level; i++) {
        printf("   "); // Spasi untuk visualisasi level
    }

    // Cetak nilai node
    printf("%d\n", root->priority);

    // Cetak subtree kiri
    printTree(root->left, level + 1);
}
