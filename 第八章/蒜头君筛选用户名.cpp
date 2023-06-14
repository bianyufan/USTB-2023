
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
    string name;//��������
    int wik;//����λ�õļ�¼��
    //һ���ṹ���ں����ֺ͸������������������������λ��
    node* next;
};//������ų�����ͬ�����ֵ�����
int main()
{
    int n;
    node* head[101];//�ٶ��������Ϊ100��
    for (int i = 1; i <= 100; i++)
        head[i] = NULL;//��ʼ��ͷ�ڵ�ΪNULL��
    cin >> n;
    string* s = new string[n];
    string* k = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);//�Ѵ�д���ַ�����ת��ΪСд���ַ���
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
            head[s[i].size()] = p;//���¼���ó������е�u���뵽������ͷ��
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
    //ע�͵�����������ʾ���ֳ��ȵ����������ֵ��������������ʹ֮���г���������⡣
    for (int i = 1; i <= 100; i++)//100�ֿ��ܳ��ȶ�Ҫ��
    {
        node* temp;
        temp = head[i];
        string st;
        while (temp)
        {
            st = temp->name;
            node* heap = temp->next;//��ÿһ������ڵ㣬�鿴������ڵ��Ƿ�������ͬ��
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

//����һ����Ĵ���
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
		// ���û���ת��ΪСд��ĸ��ʽ
		for (char& c : username) 
			c = tolower(c);
		// ����û����Ƿ��Ѿ����ֹ�
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