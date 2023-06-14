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
//题目的意思是找出1~n之中第一个没有出现过的正整数