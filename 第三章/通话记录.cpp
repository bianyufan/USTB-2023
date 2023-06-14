#include <iostream>
#include <deque>
using namespace std;
class Queue
{
public:
	deque<string>q;
	//��������
	Queue()
	{
		q.clear();
	}
	//����Ԫ��
	void add(string str)
	{
		q.push_back(str);
	}
	//���ض���Ԫ�ص�ֵ
	string get_front()
	{
		if (q.size() > 0) return q.front();
		else return"0";
	}
	//��������Ԫ��
	void pop_front()
	{
		//�ж��Ƿ�Ϊ��
		if (q.size() > 0) q.pop_front();
	}
};
int main()
{
	int a;
	string b;
	Queue q[3];  //�����������У��������ֲ�ͬ��ͨ����¼
	while (cin >> a >> b)
	{
		q[a].add(b);   //�嵽��Ӧ�Ķ��к�
	}
	for (int i = 0; i < 10; i++)
	{
		//�������Ԫ��
		cout << q[0].get_front() << " " << q[1].get_front() << " " << q[2].get_front() << endl;
		//ɾ������Ԫ��
		q[0].pop_front();
		q[1].pop_front();
		q[2].pop_front();
	}
	return 0;
}