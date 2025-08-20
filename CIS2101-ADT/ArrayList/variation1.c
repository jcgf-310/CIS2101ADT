#include <stdio.h>

#define size 10

typedef struct {
    int elem[size];
    int count;
} List;

List initialize (List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main() {
    List L;
    L.count = 0;

    L = insertPos(L, 2, 0);
    L = insertPos(L, 7, 1);
    L = insertPos(L, 3, 1);
    display(L);

    L = deletePos(L, 1);
    display(L);

    printf("Position of 2: %d\n", locate(L, 10));
    printf("Position of 3: %d\n", locate(L, 7));

    L = insertSorted(L, 8);
    L = insertSorted(L, 23);
    display(L);

    return 0;
}

List initialize (List L){

    L.count = 0;
    for (int i=0; i<size; i++){
        L.elem[i] = -1;
    }

    return L;
}

List insertPos(List L, int data, int position) {
    if (L.count < size && position >= 0 && position <= L.count) {
        for (int i = L.count; i > position; i--) {
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position) {
    if (position >= 0 && position < L.count) {
        for (int i = position; i < L.count - 1; i++) {
            L.elem[i] = L.elem[i + 1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) {
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data) {
    if (L.count < size) {
        int pos = 0;
        while (pos < L.count && L.elem[pos] < data) {
            pos++;
        }
        L = insertPos(L, data, pos);
    }
    return L;
}

void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}
