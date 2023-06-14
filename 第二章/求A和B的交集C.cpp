#include<iostream>
#include<list>
using namespace std;
//节点类型描述
typedef struct Node {
    int data;
    struct Node* next;
}linknode, * link;
//求链表的长度
int ListLength(link L) {
    int i = 0;
    link p = L->next;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}
//创建链表
link Creatlist(int n)
{
    link h, p, q; //设置三个结点，h保存la的头节点，q一直指向la的尾结点，p存储输入数据;
    h = (link)malloc(sizeof(linknode));
    h->next = NULL; //初始化链表 ,让它成为一个空表 
    q = h;  //开始时la的头结点与尾结点重合 
    for (int i = 0; i < n; i++) 
    {
        p = (link)malloc(sizeof(linknode));
        cin >> p->data;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    return h;
}
//求两个链表的交集
void Sortlist(link &L1, link &L2, link &L3)
{
    L3 = (link)malloc(sizeof(linknode));
    link p, q, r, s;
    p = L1->next;
    q = L2->next;
    r = L3;
    while (p && q)
    {
        if (p->data < q->data)
            p = p->next;
        else if (p->data > q->data)
            q = q->next;
        else
        {
            s = (link)malloc(sizeof(linknode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
}
//输出链表元素
void ShowList(link L)
{
    if (L->next == NULL)return;//a0也不能为空
    else if (L != NULL)
    {
        link p = L->next;
        while (p->next)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << p->data << endl;
    }
}
int main()
{
    int a, b;     //la，lb元素的个数
    link La = NULL;
    link Lb = NULL;
    link Lc = NULL;
    //输入La， Lb
    cin >> a;
    La = Creatlist(a);
    cin >> b;
    Lb = Creatlist(b);
    //求La， Lb的交集，存入Lc中
    Sortlist(La, Lb, Lc);
    //输出Lc的长度
    cout << ListLength(Lc) << endl;
    //输出链表Lc的元素
    ShowList(Lc);
}

