#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void printLinkedList(Node* node);
void tambahAwalNode(Node** node, int data);
void tambahSebelumNode(Node** head,int data, int i);
void tambahSesudahNode(Node** head, int data, int i);
void tambahAkhirNode(Node** head, int new_data);
void hapusAwalNode(Node** node);
void hapusNodeTertentu(Node** head, int i);
void hapusAkhirNode(Node** head);



int main(){
    char temporaryKey;
    int jumlah = 0;
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 15;
    head->next = second;

    second->data = 25;
    second->next = third;

    third->data = 50;
    third->next = NULL;

    printf("Linked List default nodes:\n");
    printLinkedList(head);
    printf("\nTekan Enter untuk melanjutkan program...");
    scanf("%c", &temporaryKey);
    int pilihan, data, tambahan, penyisipan, penghapusan, sebelum, sesudah;
    while(1){
    printf("=== Program Single Linked List ===\n");
    printf("1. Print Linked List\n");
    printf("2. Menyisipkan Node ke Linked List\n");
    printf("3. Menghapus Node di Linked List\n");
    printf("4. Keluar Program\n");
    printf("Pilih nomor program: ");
    scanf("%d", &pilihan);
    printf("\n");
    switch(pilihan){
        case 1:
            printf("Linked List nodes:\n");
            printLinkedList(head);
            printf("\n");
            break;
        case 2:
            printf("Pilihan penyisipan node!\n");
            printf("1. Awal node\n");
            printf("2. Sebelum node tertentu\n");
            printf("3. Sesudah node tertentu\n");
            printf("4. Akhir node\n");
            printf("Anda ingin menambahkan pada: ");
            scanf("%d", &penyisipan);
            printf("\n");
            switch(penyisipan){
                case 1:
                    printf("Masukkan data: ");
                    scanf("%d", &data);
                    printf("\n");
                    tambahAwalNode(&head, data);
                    // printLinkedList(head);
                    break;
                case 2:
                    printLinkedList(head);
                    printf("Sisipkan node sebelum node ke-: ");
                    scanf("%d", &sebelum);
                    printf("Masukkan data: ");
                    scanf("%d", &data);
                    printf("\n");
                    tambahSebelumNode(&head, data, sebelum);
                    // printLinkedList(head);
                    break;
                case 3:
                    printLinkedList(head);
                    printf("Sisipkan node sesudah node ke-: ");
                    scanf("%d", &sesudah);
                    printf("Masukkan data: ");
                    scanf("%d", &data);
                    printf("\n");
                    tambahSesudahNode(&head, data, sesudah);
                    // printLinkedList(head);
                    break;
                case 4:
                    printf("Masukkan data: ");
                    scanf("%d", &data);
                    printf("\n");
                    tambahAkhirNode(&head, data);
                    // printLinkedList(head);
                    break;
                default:
                    printf("Pilih nomor penyisipan!!\n\n");
                    break;
            }
            break;
        case 3:
            printf("Pilihan cara penghapusan node!\n");
            printf("1. Awal node\n");
            printf("2. Node tertentu\n");
            printf("3. Akhir node\n");
            printf("Anda ingin menghapus pada: ");
            scanf("%d", &penghapusan);
            printf("\n");
            switch(penghapusan){
                case 1:
                    hapusAwalNode(&head);
                    // printLinkedList(head);
                    break;
                case 2:
                    printLinkedList(head);
                    printf("Hapus node ke-: ");
                    scanf("%d", &sebelum);
                    printf("\n");
                    hapusNodeTertentu(&head, sebelum);
                    // printLinkedList(head);
                    break;
                case 3:
                    hapusAkhirNode(&head);
                    // printLinkedList(head);
                    break;
                default:
                    printf("Pilih nomor penyisipan!!\n\n");
                    break;
            }
            break;
        case 4:
            printf("Program berhenti...");
            return 0;
        default:
            printf("Masukkan nomor dari program yang ingin dipilih!!\n\n");
            break;
    }
    }
    return 0;
}



void printLinkedList(Node* node){
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");       
}

void tambahAwalNode(Node** head, int new_data){
    Node* new_node = (Node*) malloc (sizeof(Node));

    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;

}
void tambahSebelumNode(Node** head, int new_data, int i){
    int j = 1;
    Node* new_node = (Node*) malloc (sizeof(Node));
    Node* before = *head;
    new_node->data = new_data;

    if (i == 1) {
        tambahAwalNode(head, new_data);
        return;
    }

    while(before != NULL && j < (i-1)){
        before = before->next;
        j++;
    }
    if (before == NULL) {
        printf("Node ke-%d tidak ada dalam list.\n", i);
        free(new_node);
        return;
    }
    new_node->next = before->next;
    before->next = new_node;
}
void tambahSesudahNode(Node** head, int new_data, int i){
    int j = 1 ;
    Node* new_node = (Node*) malloc (sizeof(Node));
    Node* after = *head;
    new_node->data = new_data;
    while(j < i && after != NULL){
        after = after->next;
        j++;
    }
    if (after == NULL) {
        printf("Node ke-%d tidak ada dalam list.\n", i);
        free(new_node);
        return;
    }
    new_node->next = after->next;
    after->next = new_node;
}
void tambahAkhirNode(Node** head, int new_data){
    Node* new_node = (Node*) malloc (sizeof(Node));
    Node* tail = *head;

    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new_node;
}
void hapusAwalNode(Node** head){
    if(*head == NULL){
        printf("List kosong, tidak ada data!!\n");
        return;
    }
    Node* hapus = *head;
    (*head) = (*head)->next;
    free(hapus);
}
void hapusNodeTertentu(Node** head, int i){
    int j = 1;
    if(*head == NULL){
        printf("List kosong, tidak ada data!!\n");
        return;
    }
    if(i == 1){
        hapusAwalNode(head);
        return;
    }
    Node* before = *head;
    Node* hapus = *head;
    if (hapus->next == NULL) {
        *head = NULL; 
        free(hapus); 
        return;
    }
    while(hapus != NULL && j < i){
        before = hapus;
        hapus = hapus->next;
        j++;
    }
    if (hapus == NULL || before == NULL) {
        printf("Node ke-%d tidak ada dalam list.\n", i);
        return;
    }
    before->next = hapus->next;
    free(hapus);
}
void hapusAkhirNode(Node** head){
    if(*head == NULL){
        printf("List kosong, tidak ada data!!\n");
        return;
    }
    Node* hapus = *head;
    Node* before = NULL;

    if (hapus->next == NULL) {
        *head = NULL; 
        free(hapus); 
        return;
    }
    
    while(hapus->next != NULL){
        before = hapus;
        hapus = hapus->next;
    }
    before->next = NULL;
    free(hapus);
}

