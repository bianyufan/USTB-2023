#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
string s;
vector<char> a(100);
void dfs(int k, int left, int right)
{
    //�ݹ鵽Ҷ�ӽڵ㣬���� s ��ֵ��ΪҶ�ӽڵ㸳ֵ
    if (left == right)
    {
        if (s[left] == '1')
        {
            a[k] = 'I';
        }
        else
        {
            a[k] = 'B';
        }
        return;
    }
    int mid = left + (right - left) / 2;
    if (left != right)
    {
        dfs(2 * k, left, mid);
        dfs(2 * k + 1, mid + 1, right);
    }

    //���ݹ��̣�����Ҷ�ӽڵ��ֵ��Ϊ��ǰ�����ĸ��ڵ㸳ֵ��
    if (a[2 * k] == 'I' && a[2 * k + 1] == 'I')
    {
        a[k] = 'I';
    }
    else if (a[2 * k] == 'B' && a[2 * k + 1] == 'B')
    {
        a[k] = 'B';
    }
    else
    {
        a[k] = 'F';
    }
}
//�������
void postorder(int k)
{
    if (k >= pow(2, n + 1))
    {
        return;
    }
    postorder(2 * k);
    postorder(2 * k + 1);
    cout << a[k];
}
int main()
{
    cin >> n;
    cin >> s;
    dfs(1, 0, s.size() - 1);
    postorder(1);
    return 0;
}
