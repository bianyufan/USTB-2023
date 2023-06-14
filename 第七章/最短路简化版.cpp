#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
using namespace std;
//创建邻接表
vector<int>AL[1001];
//记录已知点到其它点的距离
int dis[1001];
queue<int>q;
//采用广度优先算法
void BFS(int k)
{
    q.push(k);
    dis[k] = 0;
    while (!q.empty())
    {
        int tmp = q.front();
        //cout << "tmp="<<tmp << endl;
        q.pop();
        int length = AL[tmp].size();
        //cout << "length=" << length << endl;
        //cout << "AL[tmp].size()=" << AL[tmp].size() << endl;
        for (int i = 0; i < length; i++)
        {
            if (dis[AL[tmp][i]] == -1) 
            {
                //cout << "tmp=" << tmp << "  i=" << i << "  AL["<<tmp<<"]["<<i<<"] = " << AL[tmp][i] << endl;
                q.push(AL[tmp][i]);               
                dis[AL[tmp][i]] = dis[tmp] + 1;
                //cout << "dis[" << AL[tmp][i] << "]=" << dis[AL[tmp][i]] << endl;
            }
        }
    }
    return;
}
int main()
{
    memset(dis, -1, sizeof(dis));
    int M, N, C;
    cin >> N >> M >> C;
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    /*
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < AL[i].size(); j++)
            cout << "AL[" << i << "][" << j << "]=" << AL[i][j] << " ";
        cout << endl;
    }*/
    BFS(C);
    for (int i = 1; i <= N; i++)
    {
        cout << dis[i] << endl;
    }
    return 0;
}