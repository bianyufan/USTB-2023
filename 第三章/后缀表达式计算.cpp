#include <iostream>
#include <stack>
#include <string>
using namespace std;
//double compute(double x1, char f, double x2);//x1和x2是两个操作数，f是运算符，函数的返回值为该运算的结果，此函数已实现

int calculate(string cal[], double& re);  // 要实现的函数
int main()
{
    string cal[100];
    int i;
    double re;
    for (i = 0; i < 100; i++)
    {
        cin >> cal[i];
        if (cal[i] == "=")break;

    }
    if (calculate(cal, re) == 0) cout << "表达式不正确";
    else cout << "=" << re;
    return 0;
}
int calculate(string cal[], double& re)
{
    stack<double> st;
    int i = 0;
    double b = 0;
    double a = 0;
    while (cal[i] != "=")
    {
        if (cal[i][0] <= '9' && cal[i][0] >= '0')
            st.push(stod(cal[i]));
        else
        {
            if (!st.empty())
            {
                b = st.top();
                st.pop();
            }
            else
                return 0;
            if (!st.empty())
            {
                a = st.top();
                st.pop();
            }
            else
                return 0;
            if (cal[i] == "+")
                st.push(a + b);
            else if (cal[i] == "-")
                st.push(a - b);
            else if (cal[i] == "*")
                st.push(a * b);
            else if (cal[i] == "/")
            {
                if (b != 0)
                {
                    st.push(a / b);
                }
                else
                    return 0;
            }
        }
        i++;
    }
    re = st.top();
    st.pop();
    if (st.empty())
        return 1;
    else
        return 0;
}