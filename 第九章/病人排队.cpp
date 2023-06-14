#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct patient
{
	string id;      //����ID
	int age;        //����
	int rank;       //�������
};
bool cmp(patient a, patient b)
{
	if (a.age >= 60 && b.age >= 60)     //����������
	{
		if (a.age == b.age)   return a.rank < b.rank;
		else return a.age > b.age;
	}
	else if (a.age < 60 && b.age < 60)   //���Ƿ�������
		return a.rank < b.rank;
	else                                 //һ�������ˣ�һ����������
		return a.age > b.age;
}
int main()
{
	int n;
	cin >> n;    //���˵ĸ���
	vector<patient>patients(n);
	for (int i = 0; i < n; i++)
	{
		cin >> patients[i].id >> patients[i].age;
		patients[i].rank = i;
	}
	sort(patients.begin(), patients.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << patients[i].id << endl;
	return 0;
}