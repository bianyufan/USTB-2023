
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
    string name;//名字内容
    int wik;//所处位置的记录量
    //一个结构，内含名字和该名字在输入的名字中所处的位置
    node* next;
};//用来存放长度相同的名字的链表
int main()
{
    int n;
    node* head[101];//假定最长的名字为100；
    for (int i = 1; i <= 100; i++)
        head[i] = NULL;//初始化头节点为NULL；
    cin >> n;
    string* s = new string[n];
    string* k = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);//把大写的字符串都转换为小写的字符串
        if (head[s[i].size()] == NULL)
        {
            node* p = new node;
            p->name = s[i];
            p->wik = i;
            head[s[i].size()] = p;
            p->next = NULL;
        }
        else if (head[s[i].size()] != NULL)
        {
            node* p = new node;
            p->name = s[i];
            p->wik = i;
            p->next = head[s[i].size()];
            head[s[i].size()] = p;//把新加入该长度序列的u插入到该链表头；
        }
    }
    /*
    node* temp;
    for (int i = 1; i <= 100; i++)
    {
        temp = head[i];
        cout << i << ":";
        while (temp)
        {
            cout << temp->name << " ";
            temp = temp->next;
        }
    }
    */
    //注释掉的内容是显示各种长度的链表内名字的收纳情况，可以使之运行出来方便理解。
    for (int i = 1; i <= 100; i++)//100种可能长度都要找
    {
        node* temp;
        temp = head[i];
        string st;
        while (temp)
        {
            st = temp->name;
            node* heap = temp->next;//找每一个链表节点，查看其后续节点是否与其相同。
            while (heap)
            {
                if (st == heap->name)
                {
                    k[temp->wik] = "Yes";
                    break;
                }
                heap = heap->next;
            }
            if (k[temp->wik] != "Yes")
                k[temp->wik] = "No";
            temp = temp->next;
        }
    }
    for (int i = 0; i < n; i++)
        cout << k[i] << endl;
    return 0;
}

//震惊我一百年的代码
/*
#include <iostream>
#include <unordered_set>
#include <string>
#include <cctype>
using namespace std;
int main() 
{
	int N;
	cin >> N;
	unordered_set<string> usernames;
	for (int i = 0; i < N; i++) 
	{
		string username;
		cin >> username;
		// 将用户名转换为小写字母形式
		for (char& c : username) 
			c = tolower(c);
		// 检查用户名是否已经出现过
		if (usernames.count(username) > 0) 
		{
			cout << "Yes" << endl;
		}
		else 
		{
			usernames.insert(username);
			cout << "No" << endl;
		}
	}
	return 0;
}
*/