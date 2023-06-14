#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> s[n];
    for (int i = 0; i < n; i++)   
        s[i].push_back(i+1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
            continue;
        if (!s[b - 1].size())
            continue;
        for (unsigned int j = 0; j < s[b - 1].size(); j++)
            s[a - 1].push_back(s[b - 1][j]);   
        vector<int> x;
        s[b - 1].swap(x);                       
    }
    for (int i = 0; i < n; i++)
    {
        if (!s[i].size())
        {
            cout << endl;
            continue;
        }
        unsigned int j;
        for (j = 0; j < s[i].size() - 1; j++)
            cout << s[i][j] << " ";
        cout << s[i][j] << endl;
    }
    return 0;
}