#include <iostream> 
using namespace std;
//节点类型描述
typedef struct Node {
	int data;
	struct Node* next, *prior;
}linknode, * link;
//创建单向循环链表
link CreSiLinkCirList(int n) 
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
	q->next = h;
	return h;
}
//转换成双向循环链表
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
//逆序输出链表
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
