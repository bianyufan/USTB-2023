#include<iostream>
#include<unordered_map>
using namespace std;
int main() 
{
	unordered_map<int, int>M;
	int n;
	cin >> n;
	for (int i = 1, val; i <= n; i++)
	{
		cin >> val;
		M[val] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!M.count(i))
		{
			cout << i;
			break;
		}
	}
	return 0;
}
//��Ŀ����˼���ҳ�1~n֮�е�һ��û�г��ֹ���������