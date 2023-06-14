#include <iostream>
#include <deque>
using namespace std;
class Queue
{
public:
	deque<string>q;
	//创建队列
	Queue()
	{
		q.clear();
	}
	//插入元素
	void add(string str)
	{
		q.push_back(str);
	}
	//返回队首元素的值
	string get_front()
	{
		if (q.size() > 0) return q.front();
		else return"0";
	}
	//弹出队首元素
	void pop_front()
	{
		//判断是否为空
		if (q.size() > 0) q.pop_front();
	}
};
int main()
{
	int a;
	string b;
	Queue q[3];  //定义三个队列，保存三种不同的通话记录
	while (cin >> a >> b)
	{
		q[a].add(b);   //插到对应的队列后
	}
	for (int i = 0; i < 10; i++)
	{
		//输出队首元素
		cout << q[0].get_front() << " " << q[1].get_front() << " " << q[2].get_front() << endl;
		//删除队首元素
		q[0].pop_front();
		q[1].pop_front();
		q[2].pop_front();
	}
	return 0;
}