#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Road 
{
	int x, y, t;
};
//�ȽϺ���
bool cmp(const Road& a, const Road& b) 
{
	return a.t < b.t;
}
//���������洢���鼯�ĸ��ڵ�
vector<int> p;
//����x�ĸ��ڵ�
int find(int x) 
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}
int kruskal(int N, int M, vector<Road>& roads) 
{
	//��t��ֵΪ���ݣ��Խڵ������������
	sort(roads.begin(), roads.end(), cmp);
	//��p�Ĵ�С����ΪN+1
	p.resize(N + 1);
	for (int i = 1; i <= N; i++)
		p[i] = i;
	int v = 1;
	int earliestTime = 0;
	for (int i = 0; i < M; i++) 
	{
		int x = find(roads[i].x);
		int y = find(roads[i].y);
		if (x != y) 
		{
			p[x] = y;
			earliestTime = max(earliestTime, roads[i].t);
			v++;
			if (v == N)
				return earliestTime;
		}
	}
	return -1;
}
int main() 
{
	int N, M;
	cin >> N >> M;
	vector<Road> roads(M);
	for (int i = 0; i < M; i++) 
	{
		cin >> roads[i].x >> roads[i].y >> roads[i].t;
	}
	int earliestTime = kruskal(N, M, roads);
	cout << earliestTime << endl;
	return 0;
}