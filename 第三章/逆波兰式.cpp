#include<iostream>
#include<stack>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//计算优先级函数
int priority(char s)
{
	if (s == '+' || s == '-')return 4;
	if (s == '*' || s == '/')return 5;
}
//中缀转后缀函数
string transform(string str)
{
	int n = str.length(); //原始字符串的长度
	stack<char>s1;        //运算符栈
	stack<char>s2;        //中间结果栈
	for (int i = 0; i < n; i++)
	{
		//数字
		if (str[i] >= '0' && str[i] <= '9')s2.push(str[i]);
		//运算符
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			while (true) 
			{
				if (s1.empty()) {
					s1.push(str[i]);
					break;
				}
				else if (priority(str[i]) > priority(s1.top())) 
				{
					s1.push(str[i]);
					break;
				}
				else 
				{
					char cc = s1.top();
					s1.pop();
					s2.push(cc);
				}
			}
		}
		else continue;
	}
	while (!s1.empty()) 
	{
		char c1 = s1.top();
		s2.push(c1);
		s1.pop();
	}
	while (!s2.empty()) 
	{
		char c2 = s2.top();
		s1.push(c2);
		s2.pop();
	}
	char hstr[20];    //后缀字符串
	for (int i = 0; !s1.empty(); i++)
	{
		hstr[i] = s1.top();  //把栈里的元素存到字符串里
		s1.pop();           //弹出栈顶元素
	}
	return hstr;	
}
//后缀得计算结果
int calcute(string str, string cal)
{
	int n = str.length(); //原始字符串的长度
	stack<int> st;
	int b = 0;
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		if (cal[i]<= '9' && cal[i] >= '0')
			st.push(int(cal[i] - '0'));   //字符转化为实际的值
		else
		{
			if (!st.empty())
			{
				b = st.top() ;
				st.pop();
			}
			else
				return 0;
			if (!st.empty())
			{
				a = st.top() ;
				st.pop();				
			}
			else
				return 0;
			if (cal[i] == '+')
				st.push(a + b);
			else if (cal[i] == '-')
				st.push(a - b);
			else if (cal[i] == '*')
				st.push(a * b);
			else if (cal[i] == '/')
			{
				if (b != 0)
				{
					st.push(a / b);
				}
				else
					return 0;
			}
		}
	}
	int s = st.top();
	st.pop();
	return s;
}
int main()
{
	string str;
	getline(cin, str);
	string str1 = transform(str);
	cout << str1 << endl;
	int result = calcute(str, str1);
	cout << result << endl;
	return 0;
}