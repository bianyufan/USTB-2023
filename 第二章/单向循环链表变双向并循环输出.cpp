#include <iostream> 
using namespace std;
//�ڵ���������
typedef struct Node {
	int data;
	struct Node* next, *prior;
}linknode, * link;
//��������ѭ������
link CreSiLinkCirList(int n) 
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
	q->next = h;
	return h;
}
//ת����˫��ѭ������
void TrDouCirList(link& L) 
{
	link p = L;
	link s;
	while (1) 
	{
		s = p->next;
		s->prior = p;
		if (p->next == L)
			break;
		p = p->next;
	}
	L->prior = p;
}
//�����������
void printByPrior(link L, int e) 
{
	link q = L -> next;
	while (q->data != e)
		q = q->next;
	link p = q;
	while (p != L) 
	{
		cout << p->data << " ";
		p = p->prior;
	}
	p = p->prior;
	while (p != q)
	{
		cout << p->data << " ";
		p = p->prior;
	}
}
int main() 
{
	int a, b;
	cin >> a;
	link L = NULL;
	L = CreSiLinkCirList(a);
	TrDouCirList(L);
	cin >> b;
	printByPrior(L, b);
	return 0;
}
