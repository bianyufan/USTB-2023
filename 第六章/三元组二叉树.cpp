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
//         佛祖保佑       永无BUG
//  本模块已经经过开光处理，绝无可能再产生bug
//=============================================
#include<iostream>
#include<deque>
using namespace std;
typedef struct Node
{
	char data;
	Node* lchild, * rchild;
}*Btree;
//构造二叉树
void CreateTree(Btree& T)
{
	char a, b, c;
	cin >> a >> b >> c;
	deque<Btree>q;
	//头节点
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
//输出二叉树的广义表达式
void print(Btree T)
{
	if (T == NULL)   return;
	cout << T->data;
	//如果左子树存在
	if (T->lchild)
	{
		cout << "(";
		print(T->lchild);
	}
	//如果左子树不存在右子树存在
	if (!T->lchild && T->rchild)
		cout << "(";
	//如果右子树存在
	if (T->rchild)
	{
		cout << ",";
		print(T->rchild);
		cout << ")";
	}
	//如果右子树不存在左子树存在
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
    char f;//父结点
    char c;//孩子
    char edge;//左孩子or右孩子
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
 
//初始化队列
void InitQueue(Queue& Q)
{
    Q.front = (QNode*)malloc(sizeof(QNode));
    Q.front->next = NULL;
    Q.rear = Q.front;
}
//入队
void EnQueue(Queue& Q, Node* node)
{
    QueuePtr temp = (QNode*)malloc(sizeof(QNode));
    temp->elem = node;
    temp->next = NULL;
    Q.rear->next = temp;
    Q.rear = temp;
}
//判断队列是否为空
bool QueueEmpty(Queue Q)
{
    if (Q.front == Q.rear) { return true; }
    return false;
}
//出队
void DeQueue(Queue& Q, BiTree& node)
{
    if (Q.front == Q.rear) { return; }
    QueuePtr temp = Q.front;
    Q.front = temp->next;
    node = Q.front->elem;
    free(temp);
    return;
}
//根据三元组序列创建二叉树
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
//广义表输出二叉树
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