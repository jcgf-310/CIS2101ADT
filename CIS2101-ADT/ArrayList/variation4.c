#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct
{
    int *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L);
void resize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List L, int data);
int retrieve(List L, int position);
void insertSorted(List *L, int data);
void display(List L);
void makeNULL(List *L);

int main()
{
    List L;

    printf("\n");
    printf("Initializing list\n");
    initialize(&L);

    printf("\n");
    printf("Inserting 1 at position 0 (first)\n");
    insertPos(&L, 1, 0);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Inserting 3 at position %d (last)\n", L.count);
    insertPos(&L, 3, L.count);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Inserting 2 at position 1\n");
    insertPos(&L, 2, 1);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Inserting 5 in sorted order\n");
    insertSorted(&L, 5);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Deleting element at position 1\n");
    deletePos(&L, 1);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Locating 5 in list: %d\n", locate(L, 5));

    printf("\n");
    printf("Deleting value 1\n");
    int pos = locate(L, 1);
    if (pos != -1)
        deletePos(&L, pos);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Retrieving element at position 1: %d\n", retrieve(L, 1));

    makeNULL(&L);

    return 0;
}

void initialize(List *L)
{
    L->elemPtr = (int *)malloc(LENGTH * sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

void resize(List *L)
{
    L->max *= 2;
    L->elemPtr = (int *)realloc(L->elemPtr, L->max * sizeof(int));
}

void insertPos(List *L, int data, int position)
{
    if (position <= L->count)
    {
        if (L->count == L->max)
        {
            resize(L);
        }
        for (int i = L->count; i > position; i--)
        {
            L->elemPtr[i] = L->elemPtr[i - 1];
        }
        L->elemPtr[position] = data;
        L->count++;
    }
}

void deletePos(List *L, int position)
{
    if (position < L->count)
    {
        for (int i = position; i < L->count - 1; i++)
        {
            L->elemPtr[i] = L->elemPtr[i + 1];
        }
        L->count--;
    }
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

int retrieve(List L, int position)
{
    if (position < L.count)
    {
        return L.elemPtr[position];
    }
    return -1;
}

void insertSorted(List *L, int data)
{
    if (L->count == L->max)
    {
        resize(L);
    }
    int i;
    for (i = L->count - 1; i >= 0 && L->elemPtr[i] > data; i--)
    {
        L->elemPtr[i + 1] = L->elemPtr[i];
    }
    L->elemPtr[i + 1] = data;
    L->count++;
}

void display(List L)
{
    for (int i = 0; i < L.count; i++)
    {
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}

void makeNULL(List *L)
{
    free(L->elemPtr);
    L->count = 0;
    L->max = 0;
}