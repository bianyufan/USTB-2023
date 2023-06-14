//                   _ooOoo_
//                  o8888888o
//                  88" . "88
//                  (| -_- |)
//                  O\  =  /O
//               ____/`---'\____
//             .'  \\|     |//  `.
//            /  \\|||  :  |||//  \
//           /  _||||| -:- |||||-  \
//           |   | \\\  -  /// |   |
//           | \_|  ''\---/''  |   |
//           \  .-\__  `-`  ___/-. /
//         ___`. .'  /--.--\  `. . __
//      ."" '<  `.___\_<|>_/___.'  >'"".
//     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//     \  \ `-.   \_ __\ /__ _/   .-` /  /
//======`-.____`-.___\_____/___.-`____.-'======
//                   `=---='
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//         ���汣��       ����BUG
//  ��ģ���Ѿ��������⴦�����޿����ٲ���bug
//=============================================
#include<iostream>
#include<deque>
using namespace std;
typedef struct Node
{
	char data;
	Node* lchild, * rchild;
}*Btree;
//���������
void CreateTree(Btree& T)
{
	char a, b, c;
	cin >> a >> b >> c;
	deque<Btree>q;
	//ͷ�ڵ�
	if (a == '^' && b != '^')
	{
		Btree node = new Node;
		node->data = b;
		node->lchild = node->rchild = nullptr;
		T = node;
		q.push_back(node);
	}
	else if (a == '^' && b == '^')
	{
		T = NULL;
		return;
	}
	else
	{
		cin >> a >> b >> c;
		while (!q.empty() && a != '^' && b != '^')
		{
			Btree p = q.front();
			q.pop_front();
			while (p->data == a)
			{
				Btree node = new Node;
				node->data = b;
				node->lchild = node->rchild = NULL;
				if (c == 'L')    p->lchild = node;
				else       p->rchild = node;
				q.push_back(node);
				cin >> a >> b >> c;
			}
		}
	}
}
//����������Ĺ�����ʽ
void print(Btree T)
{
	if (T == NULL)   return;
	cout << T->data;
	//�������������
	if (T->lchild)
	{
		cout << "(";
		print(T->lchild);
	}
	//�������������������������
	if (!T->lchild && T->rchild)
		cout << "(";
	//�������������
	if (T->rchild)
	{
		cout << ",";
		print(T->rchild);
		cout << ")";
	}
	//�������������������������
	if (!T->rchild && T->lchild)
		cout << ")";
	return;
}
int main()
{
	Btree T;
	CreateTree(T);
	print(T);
	return 0;
}
/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
typedef struct unite
{
    char f;//�����
    char c;//����
    char edge;//����or�Һ���
};
typedef struct Node
{
    char data;
    Node* lc, * rc;
}*BiTree;
typedef struct QNode
{
    Node* elem;
    QNode* next;
}*QueuePtr;
typedef struct Queue
{
    QueuePtr front, rear;
};
 
//��ʼ������
void InitQueue(Queue& Q)
{
    Q.front = (QNode*)malloc(sizeof(QNode));
    Q.front->next = NULL;
    Q.rear = Q.front;
}
//���
void EnQueue(Queue& Q, Node* node)
{
    QueuePtr temp = (QNode*)malloc(sizeof(QNode));
    temp->elem = node;
    temp->next = NULL;
    Q.rear->next = temp;
    Q.rear = temp;
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue Q)
{
    if (Q.front == Q.rear) { return true; }
    return false;
}
//����
void DeQueue(Queue& Q, BiTree& node)
{
    if (Q.front == Q.rear) { return; }
    QueuePtr temp = Q.front;
    Q.front = temp->next;
    node = Q.front->elem;
    free(temp);
    return;
}
//������Ԫ�����д���������
BiTree create(unite* a,int len)
{
    if (len < 1) {  return  NULL; }
    BiTree T = (Node*)malloc(sizeof(Node));
    T->data = a[0].c; T->lc = NULL; T->rc = NULL;
    if (len == 1) { return T; }
    Node* innode, *outnode = T;
    Queue Q;
    InitQueue(Q);
    EnQueue(Q, outnode);
    for (int i = 1; i < len; i++)
    {
        innode= (Node*)malloc(sizeof(Node));
        innode->data = a[i].c; innode->lc = NULL; innode->rc = NULL;
        EnQueue(Q,innode);
        if (a[i].f == a[i - 1].c || (a[i].f!=a[i-1].f && a[i].f!=a[i-1].c))
        {
            DeQueue(Q, outnode);
        }
        if(a[i].f!=outnode->data){DeQueue(Q,outnode);}
        if (a[i].edge == 'L') { outnode->lc = innode; }
        else { outnode->rc = innode; }
    }
    return T;
}
//��������������
void print(BiTree T)
{
    if (T == NULL) { return; }
    cout << T->data;
    if (T->lc) { cout << "("; print(T->lc); }
    if (!T->lc && T->rc) { cout << "("; }
    if (T->rc) { cout << ","; print(T->rc); cout << ")"; }
    if (!T->rc && T->lc) { cout << ")"; }
    return;
}
 
int main()
{
    unite a[100];
    int i = 0;
    while (1)
    {
        cin >> a[i].f >> a[i].c >> a[i].edge;
        if (a[i].f == '^' && a[i].c == '^') { break; }
        i++;
    }
    BiTree T=create(a,i);
    print(T);
    return 0;
}
*/