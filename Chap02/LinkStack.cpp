#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAXSIZE 10
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkStack;
ElemType *array;
LinkStack InitStack(LinkStack &Li);
void showStack(LinkStack Li);
ElemType *PopStack(LinkStack &Li, ElemType *array);
int main(void)
{
    LinkStack Li;
    LinkStack res = InitStack(Li);
    array = new ElemType[MAXSIZE];
    showStack(res);
    cout << '\n';
    ElemType *resArr = PopStack(res, array);
    for (int i = 0; i < 4; i++)
    {
        cout << resArr[i] << endl;
    }
    return 0;
}
LinkStack InitStack(LinkStack &Li)
{
    LNode *L; // HEAD Node
    L = new LNode;
    L->next = NULL;
    LNode *s;
    ElemType x;
    while ((scanf("%d", &x) != EOF))
    {
        s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
    }
    return L;
}
void showStack(LinkStack Li)
{
    LNode *tmp;
    tmp = Li->next;
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
ElemType *PopStack(LinkStack &Li, ElemType *array)
{

    LNode *tmp = Li->next;
    int cnt = 0;
    for (int i = 0; tmp != NULL; i++)
    {
        array[i] = tmp->data;
        tmp = tmp->next;
        cnt++;
    }

    return array;
}