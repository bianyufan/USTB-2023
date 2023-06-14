#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct patient
{
	string id;      //病人ID
	int age;        //年龄
	int rank;       //输入次序
};
bool cmp(patient a, patient b)
{
	if (a.age >= 60 && b.age >= 60)     //都是老年人
	{
		if (a.age == b.age)   return a.rank < b.rank;
		else return a.age > b.age;
	}
	else if (a.age < 60 && b.age < 60)   //都是非老年人
		return a.rank < b.rank;
	else                                 //一个老年人，一个非老年人
		return a.age > b.age;
}
int main()
{
	int n;
	cin >> n;    //病人的个数
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