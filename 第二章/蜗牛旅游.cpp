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
    // ��������� 
    long long m;
    // ����
    for (int i = 0; i < t; i++) 
    {
        cin>>m;
        list[i] =m;
    }
 long long max = 0;
    for (int i = 0; i < t; i++) 
    {
        // �ж��Ƿ��ڶ�����
        if (mark[list[i]] == 0) 
        {
            // �����ڣ��������
            qu.push(list[i]);
            // �������
            mark[list[i]] = 1;
        } 
        else 
        {
            // ���ڣ�������Ԫ�س���ֱ��û��Ԫ�غͼ�������ӵ�Ԫ���ظ�
            while (mark[list[i]] != 0) 
            {
                mark[qu.front()] = 0;
                qu.pop();
            }
            // �������
            qu.push(list[i]);
            // �������
            mark[list[i]] = 1;
        }
        // �洢�����
        if (qu.size() > max) 
            max = qu.size();
    }
    cout<<max;
}