#include<iostream>
using namespace std;
//�ڵ���������
typedef struct Node {
	int data;
	struct Node* next;
}linknode, * link;
//��������
link CreatList(int n)
{
    link h, p, q; //����������㣬h����la��ͷ�ڵ㣬qһֱָ��la��β��㣬p�洢��������;
    h = (link)malloc(sizeof(linknode));
    h->next = NULL; //��ʼ������ ,������Ϊһ���ձ� 
    q = h;  //��ʼʱla��ͷ�����β����غ� 
    for (int i = 0; i < n; i++)
    {
        p = (link)malloc(sizeof(linknode));
        p->data = i + 1;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    return h;
}
//ɾ���ڵ�
link DeleteNode(link L, int n)
{
    link p = L;
    link r = NULL;
    if (L == NULL)  return NULL;
    //if (L->data) return L->next;
    for (int i = 0; i < n; i++)
    {
        r = p;
        p = p->next;
    }
    r->next = p->next;
    free(p);
    return L;
}
//����м�����
void print_id(link L, int n)
{
    link p = L;
    for (int i = 0; i < n / 2 + 1; i++)
    {
        p = p->next;
    }
    cout << p->data<<endl;
}
int main()
{
	int N, M;
	cin >> N >> M ;
	link linklist = NULL;
    //��������
	linklist = CreatList(N);
    //ɾ���ڵ�
    for (int i = 0; i < M; i++)
    {
        int number;
        cin >> number;
        linklist = DeleteNode(linklist, number);
        N--;
    }
    //�������
    print_id(linklist, N);
    return 0;
}