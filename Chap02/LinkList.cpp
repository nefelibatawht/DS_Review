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
// 按序号查询结点
LNode *GetElem(LinkList L, int i);
// 按值查找结点，返回结点的序号
int GetElemByVal(LinkList L, int e);
// 结点的插入操作(其中结点的数据域值为e，插入第i个位置)
LinkList InsertNode(LinkList &L, int i, int e);
int main(void)
{
    LinkList L = NULL;
    int cnt;
    // List_HeadInsert(L);
    List_TailInsert(L);
    showLinkList(L);
    // scanf("%d", &cnt);
    //  LNode *res = GetElem(L, cnt);
    // int res = 0;
    // res = GetElemByVal(L, cnt);
    // cout << "\n" << res << endl;
    LinkList res = InsertNode(L, 3, 12);
    cout << "\n";
    showLinkList(res);
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
LNode *GetElem(LinkList L, int i)
{
    if (i < 1)
    {
        exit(1);
    }
    int j = 1; // 计数器作用
    LNode *tmp = L->next;
    while (tmp != NULL && j < i)
    {
        tmp = tmp->next;
        j++;
    }
    return tmp;
}

int GetElemByVal(LinkList L, int e)
{
    int cnt = 1;
    LNode *tmp = L->next;
    while (tmp != NULL && (tmp->data != e))
    {
        tmp = tmp->next;
        cnt++;
    }
    return cnt;
}
LinkList InsertNode(LinkList &L, int i, int e)
{
    LNode *tmp = GetElem(L, i);
    LNode *insertElem = new LNode;
    insertElem->data = e;
    insertElem->next = tmp->next;
    tmp->next = insertElem;
    int temp = tmp->data;
    tmp->data = insertElem->data;
    insertElem->data = temp;
    return L;
}