#include <iostream>
#include <unordered_set>
using namespace std;
int main() 
{
    int m, n;
    cin >> m >> n;
    unordered_set<int> balls;
    //ÊäÈëÇòºÅ
    for (int i = 0; i < m; i++) 
    {
        int num;
        cin >> num;
        balls.insert(num);
    }
    //nÂÖ±ÈÈüÕÒÇòºÅ
    for (int i = 0; i < n; i++) 
    {
        int num;
        cin >> num;
        if (balls.count(num)) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}