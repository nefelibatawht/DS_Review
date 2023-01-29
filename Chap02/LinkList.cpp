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
// 结点的删除
LinkList deleteNode(LinkList &L, int i);
// 后插法插入节点
LinkList InsertNodeTail(LinkList &L, int i, int e);
// 求表长（不含头结点）
int getLength(LinkList L);
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
    LinkList res = InsertNodeTail(L, 2, 12);
    cout << "\n";
    // LinkList res = deleteNode(L, 2);
    showLinkList(res);
    cout << "\n";
    // int numRes = getLength(L);
    // cout << numRes << endl;
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
    LNode *tmp = L->next; // 忽略头结点对计数的影响
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
LinkList deleteNode(LinkList &L, int i)
{
    LNode *front = GetElem(L, i - 1);
    LNode *del = front->next;
    front->next = del->next;
    free(del);
    return L;
}

int getLength(LinkList L)
{
    int cnt = 0;
    LNode *tmp = L->next;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        cnt++;
    }
    return cnt;
}
LinkList InsertNodeTail(LinkList &L, int i, int e)
{
    if (i == 1)
    {
        LNode *tmp = L;
        LNode *ins = new LNode;
        ins->data = e;
        ins->next = tmp->next;
        L->next = ins;
    }
    else
    {
        LNode *tmp = GetElem(L, i - 1);
        LNode *ins = new LNode;
        ins->data = e;
        ins->next = tmp->next;
        tmp->next = ins;
    }
    return L;
}