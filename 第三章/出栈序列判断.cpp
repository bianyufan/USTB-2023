#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void ispoporder(queue<int>q, int n)
{
	stack<int>s; //����ջ

	for (int i = 0; i < n; i++)
	{
		s.push(i + 1);
		while (!s.empty() && s.top() == q.front())
		{
			s.pop();
			q.pop();
		}
	}
	if (!s.empty())cout << "NO";
	else cout << "YES";
}
int main()
{
	int n;
	queue<int>m; //�������д�Ŵ�����������
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		m.push(k);
	}
	ispoporder(m, n);
	return 0;
}