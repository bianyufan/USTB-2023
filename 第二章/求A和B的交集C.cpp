#include<iostream>
#include<list>
using namespace std;
//�ڵ���������
typedef struct Node {
    int data;
    struct Node* next;
}linknode, * link;
//������ĳ���
int ListLength(link L) {
    int i = 0;
    link p = L->next;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}
//��������
link Creatlist(int n)
{
    link h, p, q; //����������㣬h����la��ͷ�ڵ㣬qһֱָ��la��β��㣬p�洢��������;
    h = (link)malloc(sizeof(linknode));
    h->next = NULL; //��ʼ������ ,������Ϊһ���ձ� 
    q = h;  //��ʼʱla��ͷ�����β����غ� 
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
//����������Ľ���
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
//�������Ԫ��
void ShowList(link L)
{
    if (L->next == NULL)return;//a0Ҳ����Ϊ��
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
    int a, b;     //la��lbԪ�صĸ���
    link La = NULL;
    link Lb = NULL;
    link Lc = NULL;
    //����La�� Lb
    cin >> a;
    La = Creatlist(a);
    cin >> b;
    Lb = Creatlist(b);
    //��La�� Lb�Ľ���������Lc��
    Sortlist(La, Lb, Lc);
    //���Lc�ĳ���
    cout << ListLength(Lc) << endl;
    //�������Lc��Ԫ��
    ShowList(Lc);
}

