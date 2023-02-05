// 栈的顺序存储
// 操作�?
/**
 * 初始�?
 * 判断是否空栈
 * 进栈
 * 出栈
 * 读取栈顶元素
 */
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXSIZE 5
typedef int ElemType;
typedef struct SqStack
{
    ElemType *data;
    int top; // 栈顶指针
} SqStack;
void InitStack(SqStack &sq);
bool EmptyStack(SqStack sq);
bool Push(SqStack &sq, ElemType *array);
void showStack(SqStack sq);
ElemType *POP(SqStack &sq);
void readTop(SqStack sq);
int main(void)
{
    SqStack sq;
    InitStack(sq);
    ElemType *arrayInput = new ElemType[MAXSIZE];
    bool res = EmptyStack(sq);
    cout << res << endl;
    ElemType x;
    for (int i = 0; i < MAXSIZE; i++)
    {
        scanf("%d", &x);
        arrayInput[i] = x;
    }
    res = Push(sq, arrayInput);
    showStack(sq);
    cout << "Top Pointer" << endl;
    cout << sq.top << endl;
    cout << "Top Elem" << endl;
    readTop(sq);
    ElemType *resArray = POP(sq);
    for (int i = 0; i < MAXSIZE; i++)
    {
        cout << "output " << i + 1 << endl;
        cout << resArray[i] << endl;
    }

    return 0;
}
void InitStack(SqStack &sq)
{
    sq.data = new ElemType[MAXSIZE];
    sq.top = -1;
}
bool EmptyStack(SqStack sq)
{
    if (sq.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Push(SqStack &sq, ElemType *array)
{
    if (sq.top == MAXSIZE - 1)
    {
        return false;
    }
    sq.top++;
    for (; sq.top < MAXSIZE; sq.top++)
    {
        sq.data[sq.top] = array[sq.top];
        if (sq.top == MAXSIZE - 1)
        {
            break;
        }
    }

    return true;
}
void showStack(SqStack sq)
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        cout << sq.data[i] << '\t' << endl;
    }
}
ElemType *POP(SqStack &sq)
{
    if (sq.top == -1)
    {
        exit(1);
    }
    ElemType *arrayOutput = new ElemType[MAXSIZE];

    for (int i = 0; sq.top >= 0, i < MAXSIZE; sq.top--, i++)
    {
        arrayOutput[i] = sq.data[sq.top];
        // cout << arrayOutput[i] << endl;
    }
    return arrayOutput;
}
void readTop(SqStack sq)
{
    if (sq.top == -1)
    {
        exit(1);
    }
    cout << sq.data[sq.top] << endl;
}