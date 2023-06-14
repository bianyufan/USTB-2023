#include <iostream>
#include<queue>
#include<vector>
using namespace std;
const int NUM = 1e6 + 1;
queue<long long> qu;
long long list[NUM]={0};
bool mark[NUM]={0};

int main()
{
    long long t;
    cin>>t;   
    // 输入的整数 
    long long m;
    // 输入
    for (int i = 0; i < t; i++) 
    {
        cin>>m;
        list[i] =m;
    }
 long long max = 0;
    for (int i = 0; i < t; i++) 
    {
        // 判断是否在队列中
        if (mark[list[i]] == 0) 
        {
            // 若不在，加入队列
            qu.push(list[i]);
            // 标记数字
            mark[list[i]] = 1;
        } 
        else 
        {
            // 若在，将队首元素出队直到没有元素和即将新入队的元素重复
            while (mark[list[i]] != 0) 
            {
                mark[qu.front()] = 0;
                qu.pop();
            }
            // 加入队列
            qu.push(list[i]);
            // 标记数字
            mark[list[i]] = 1;
        }
        // 存储最长队列
        if (qu.size() > max) 
            max = qu.size();
    }
    cout<<max;
}