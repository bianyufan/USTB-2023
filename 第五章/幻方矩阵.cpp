#include<iostream>
using namespace std;
int row[100005];//记录初始行交换后的新行
int col[100005];//记录初始列对应的新列
int a[100005];
int hd[100005];//记录当前下标行对应的初始行
int ld[100005];//记录当前下标列对应的初始列
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m * n; i++)
		cin >> a[i];
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[m * (i - 1) + j];
		}
	}
	*/
	for (int i = 1; i <= n; i++) 
	{
		row[i] = i;
		hd[i] = i;
	}
	for (int i = 1; i <= m; i++) 
	{
		col[i] = i;
		ld[i] = i;
	}
	int k;
	cin >> k;
	while (k--) 
	{
		int f, x, y;
		cin >> f >> x >> y;
		if (f == 0) 
		{
			swap(row[hd[x]], row[hd[y]]);
			swap(hd[x], hd[y]);
		}
		else 
		{
			swap(col[ld[x]], col[ld[y]]);
			swap(ld[x], ld[y]);
		}
	}
	int d[100005];
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++)
		{
			d[m * (row[i] - 1) + col[j]] = a[m * (i - 1) + j];
		}

	}
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++) 
		{
			cout << d[m * (i - 1) + j];
			if (j < m) cout << " ";
		}
		cout << endl;
	}
}
/*
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//输入行数和列数
	int m, n;
	cin >> m >> n;
	//输入矩阵
	vector<vector<int>>a(100000);
	for (int i = 0; i < a.size(); i++)
		a[i].resize(100000);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}	
	//输入操作数
	int k;
	cin >> k;
	//输入操作流程
	for (int i = k; i > 0; i--)
	{
		int f, x, y;
		cin >> f >> x >> y;
		if (f == 0)
		{
			for (int j = 0; j < n; j++)			
				swap(a[x - 1][j], a[y - 1][j]);			
		}
		else
		{
			for (int j = 0; j < m; j++)
				swap(a[j][x - 1], a[j][y - 1]);
		}
	}
	//输出最终结果
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
*/