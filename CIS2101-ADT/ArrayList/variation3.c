#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct
{
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List resize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main()
{
    List L;

    printf("\n");
    printf("Initializing list\n");
    L = initialize(L);

    printf("\n");
    printf("Inserting 1 at position 0 (first)\n");
    L = insertPos(L, 1, 0);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Inserting 3 at position %d (last)\n", L.count);
    L = insertPos(L, 3, L.count);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Inserting 2 at position 1\n");
    L = insertPos(L, 2, 1);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Inserting 5 in sorted order\n");
    L = insertSorted(L, 5);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Deleting element at position 1\n");
    L = deletePos(L, 1);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Locating 5 in list: %d\n", locate(L, 5));

    printf("\n");
    printf("Deleting value 1\n");
    int pos = locate(L, 1);
    if (pos != -1)
        L = deletePos(L, pos);
    printf("Current list: ");
    display(L);

       free(L.elemPtr);
    return 0;
}

List initialize(List L)
{
    L.elemPtr = (int *)malloc(LENGTH * sizeof(int));
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List resize(List L)
{
    L.max *= 2;
    L.elemPtr = (int *)realloc(L.elemPtr, L.max * sizeof(int));
    return L;
}

List insertPos(List L, int data, int position)
{
    if (position <= L.count)
    {
        if (L.count == L.max)
        {
            L = resize(L);
        }
        for (int i = L.count; i > position; i--)
        {
            L.elemPtr[i] = L.elemPtr[i - 1];
        }
        L.elemPtr[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position)
{
    if (position < L.count)
    {
        for (int i = position; i < L.count - 1; i++)
        {
            L.elemPtr[i] = L.elemPtr[i + 1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int data)
{
    for (int i = 0; i < L.count; i++)
    {
        if (L.elemPtr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data)
{
    if (L.count == L.max)
    {
        L = resize(L);
    }
    int i;
    for (i = L.count - 1; i >= 0 && L.elemPtr[i] > data; i--)
    {
        L.elemPtr[i + 1] = L.elemPtr[i];
    }
    L.elemPtr[i + 1] = data;
    L.count++;
    return L;
}

void display(List L)
{
    for (int i = 0; i < L.count; i++)
    {
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}