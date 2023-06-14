#include<iostream>
using namespace std;
//节点类型描述
typedef struct Node {
	int data;
	struct Node* next;
}linknode, * link;
//创建链表
link CreatList(int n)
{
    link h, p, q; //设置三个结点，h保存la的头节点，q一直指向la的尾结点，p存储输入数据;
    h = (link)malloc(sizeof(linknode));
    h->next = NULL; //初始化链表 ,让它成为一个空表 
    q = h;  //开始时la的头结点与尾结点重合 
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
//删除节点
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
//输出中间数字
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
    //创建链表
	linklist = CreatList(N);
    //删除节点
    for (int i = 0; i < M; i++)
    {
        int number;
        cin >> number;
        linklist = DeleteNode(linklist, number);
        N--;
    }
    //输出数字
    print_id(linklist, N);
    return 0;
}