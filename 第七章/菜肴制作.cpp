#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 100010
using namespace std;
priority_queue<int> q;
int N, M, C;
int head[MAXN], din[MAXN], vec[MAXN];
struct Edge 
{
    int next, to;
}a[MAXN];
//向图的邻接表中添加一条边
void add(int x, int y) 
{
    a[C].to = y; 
    //将起点 x 对应的头结点的值赋值给 a[C].next
    a[C].next = head[x]; 
    //更新起点 x 的头结点为当前添加的边 C,自增变量c
    head[x] = C++;
}
void Topo_Sort() 
{
    int u, v, num = 0, top = 0;
    while (!q.empty())q.pop();
    for (int i = 1; i <= N; i++)
        if (!din[i])   //如果入度为 0，表示该顶点可以作为拓扑排序的起始点
        { 
            q.push(i); 
            num++;
        }
    //不断从优先队列q中取出顶点并进行处理
    while (!q.empty()) 
    {
        u = q.top();
        q.pop();
        vec[++top] = u;
        for (int i = head[u]; i; i = a[i].next) 
        {
            v = a[i].to;
            din[v]--;
            if (!din[v]) 
            {
                q.push(v);
                num++;
            }
        }
    }
    //判断是否存在环路
    if (num < N)
        cout << "Impossible!" << endl;
    //从后向前输出
    else 
    {
        for (int i = N; i >= 1; i--)
            cout<<vec[i]<<" ";
        cout << endl;
    }
}
//初始化
void init() 
{
    int x, y;
    C = 1;  //记录边的索引
    //将head和din的值全部置为0
    memset(head, 0, sizeof(head));
    memset(din, 0, sizeof(din));
    cin >> N >> M;
    for (int i = 1; i <= M; i++) 
    {
        cin >> x >> y;
        add(y, x);
        din[x]++;
    }
}
int main() 
{
    int D ;
    cin >> D;
    while (D--) 
    {
        init();
        Topo_Sort();
    }
    return 0;
}