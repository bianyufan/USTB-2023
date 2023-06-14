#include <iostream>
using namespace std;
int main() 
{
    int d, n;
    while (cin >> d >> n, d || n) 
    {
        int ans = 1;
        for (int i = 1; i < d; i++) 
        {
            if (n % 2) 
            {
                ans *= 2;
                n = (n + 1) / 2;
            }
            else
            {
                ans = ans * 2 + 1;
                n /= 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}