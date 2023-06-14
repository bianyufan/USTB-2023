#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
string s;
vector<char> a(100);
void dfs(int k, int left, int right)
{
    //递归到叶子节点，根据 s 的值来为叶子节点赋值
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

    //回溯过程：根据叶子节点的值来为当前子树的根节点赋值。
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
//后序遍历
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
