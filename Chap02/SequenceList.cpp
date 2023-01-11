#define __CRT_SECURE_NO_WARNINGS 1
#define __CRT_SECURE_NO_WARNINGS 1
// 2.1-2.2
#include <iostream>
using namespace std;
#define MAXSIZE 50
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} SqList;

bool InitList(SqList &L);
bool InsertList(SqList &L, int i, int e);
void showList(SqList L);
bool deleteList(SqList &L, int e);
int LocateList(SqList L, int e);
bool DestroyList(SqList &L);

int main(void)
{
    SqList L;
    bool status = InitList(L);
    status = InsertList(L, 1, 2);
    status = InsertList(L, 2, 20);
    status = InsertList(L, 3, 200);
    status = InsertList(L, 4, 2000);
    status = InsertList(L, 5, 20000);
    status = InsertList(L, 6, 200000);

    showList(L);
    cout << L.length << endl;
    status = deleteList(L, 3);
    showList(L);
    cout << L.length << endl;
    cout << "Locate " << LocateList(L, 2000) << endl;
    status = DestroyList(L);
    showList(L);
    cout << "Finish Delete " << endl;

    cout << L.length << endl;

    return 0;
}

bool InitList(SqList &L)
{
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem)
    {
        return false;
    }
    L.length = 0;
    return true;
}

bool InsertList(SqList &L, int i, int e)
{

    if ((i < 1) || i > L.length + 1)
    {
        return false;
    }
    if (L.length >= MAXSIZE)
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    L.length++;
    return true;
}

void showList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\n", L.elem[i]);
    }
}

bool deleteList(SqList &L, int i)
{
    if ((i < 1) || i > L.length)
    {
        return false;
    }
    for (int j = i; j < L.length; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return true;
}

int LocateList(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            return i + 1;
        }
    }
}
bool DestroyList(SqList &L)
{
    delete[] L.elem;
    L.length = 0;
    return true;
}