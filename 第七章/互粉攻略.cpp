#include<iostream>
using namespace std;
int main() 
{
	//�ڽӾ���
	bool vec[1000][1000];
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a][b] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		int din = 0;   //���
		int dout = 0;  //����
		for (int j = 0; j < n; j++)
		{
			din = din + vec[j][i];
			dout = dout + vec[i][j];
		}
		cout << din - dout << endl;
	}
	return 0;
}
