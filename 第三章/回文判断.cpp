#include<iostream>
#include<deque>
#include<string>
using namespace std;

void ispalindrome(deque<int>q)
{
	while (q.size() > 1 && q.front() == q.back())
	{
		q.pop_back();
		q.pop_front();
	}
	if (q.size() <= 1)  cout << "true" << endl;
	else cout << "false" << endl;
}
int main()
{
	deque<int>q; //创建队列存放待测数据序列
	char k;
	while (cin >> k)
	{
		if (k != '@')
			q.push_back(k);
		else break;
	}
	ispalindrome(q);
	return 0;
}