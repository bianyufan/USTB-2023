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
//��ͼ���ڽӱ������һ����
void add(int x, int y) 
{
    a[C].to = y; 
    //����� x ��Ӧ��ͷ����ֵ��ֵ�� a[C].next
    a[C].next = head[x]; 
    //������� x ��ͷ���Ϊ��ǰ��ӵı� C,��������c
    head[x] = C++;
}
void Topo_Sort() 
{
    int u, v, num = 0, top = 0;
    while (!q.empty())q.pop();
    for (int i = 1; i <= N; i++)
        if (!din[i])   //������Ϊ 0����ʾ�ö��������Ϊ�����������ʼ��
        { 
            q.push(i); 
            num++;
        }
    //���ϴ����ȶ���q��ȡ�����㲢���д���
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
    //�ж��Ƿ���ڻ�·
    if (num < N)
        cout << "Impossible!" << endl;
    //�Ӻ���ǰ���
    else 
    {
        for (int i = N; i >= 1; i--)
            cout<<vec[i]<<" ";
        cout << endl;
    }
}
//��ʼ��
void init() 
{
    int x, y;
    C = 1;  //��¼�ߵ�����
    //��head��din��ֵȫ����Ϊ0
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