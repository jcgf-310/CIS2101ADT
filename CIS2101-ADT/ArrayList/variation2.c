#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main()
{
    Etype Lstruct;
    EPtr L = &Lstruct;

    printf("\n");
    printf("Initializing list\n");
    initialize(L);

    printf("\n");
    printf("Inserting 1 at position 0 (first)\n");
    insertPos(L, 1, 0);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Inserting 3 at position %d (last)\n", L->count);
    insertPos(L, 3, L->count);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Inserting 2 at position 1\n");
    insertPos(L, 2, 1);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Inserting 5 in sorted order\n");
    insertSorted(L, 5);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Deleting element at position 1\n");
    deletePos(L, 1);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Locating 5 in list: %d\n", locate(L, 5));

    printf("\n");
    printf("Deleting value 1\n");
    int pos = locate(L, 1);
    if (pos != -1)
        deletePos(L, pos);
    printf("Current list: ");
    display(L);

    printf("\n");
    printf("Retrieving element at position 1: %d\n", retrieve(L, 1));

    makeNULL(L);
    return 0;
}

void initialize(EPtr L)
{
    L->count = 0;
}

void insertPos(EPtr L, int data, int position)
{
    if (position <= L->count && L->count < MAX)
    {
        for (int i = L->count; i > position; i--)
        {
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(EPtr L, int position)
{
    if (position < L->count)
    {
        for (int i = position; i < L->count - 1; i++)
        {
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }
}

int locate(EPtr L, int data)
{
    for (int i = 0; i < L->count; i++)
    {
        if (L->elem[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position)
{
    if (position < L->count)
    {
        return L->elem[position];
    }
    return -1;
}

void insertSorted(EPtr L, int data)
{
    if (L->count < MAX)
    {
        int i;
        for (i = L->count - 1; i >= 0 && L->elem[i] > data; i--)
        {
            L->elem[i + 1] = L->elem[i];
        }
        L->elem[i + 1] = data;
        L->count++;
    }
}

void display(EPtr L)
{
    for (int i = 0; i < L->count; i++)
    {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(EPtr L)
{
    L->count = 0;
}