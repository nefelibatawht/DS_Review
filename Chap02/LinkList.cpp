#include <iostream>
using namespace std;
#define MAXSIZE 50;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 使用前插法创建链表
LinkList List_HeadInsert(LinkList &L);
// 使用后插法创建链表
LinkList List_TailInsert(LinkList &L);
//
void showLinkList(LinkList L);
int main(void)
{
    LinkList L = NULL;
    // List_HeadInsert(L);
    List_TailInsert(L);
    showLinkList(L);
    return 0;
}
LinkList List_HeadInsert(LinkList &L)
{
    int input;
    L = new LNode;
    LNode *s;
    L->next = NULL;
    ;
    while (scanf("%d", &input) != EOF)
    {
        s = new LNode;
        s->data = input;
        s->next = L->next;
        L->next = s;
    }
    return L;
}
LinkList List_TailInsert(LinkList &L)
{
    int input;
    L = new LNode;
    L->next = NULL;
    LNode *s, *r = L;
    while (scanf("%d", &input) != EOF)
    {
        s = new LNode;
        s->data = input;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
}
void showLinkList(LinkList L)
{
    LNode *tmp = L->next;
    while (tmp != NULL)
    {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    }
}