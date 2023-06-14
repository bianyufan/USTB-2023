#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//����һ���ṹ��洢DNA�ַ������������
struct DNA {
    string str;
    int back;
    int cnt; //�������
};

//����������򣬰������������С������ͬ�İ����������
bool cmp(DNA a, DNA b) {
    if (a.back != b.back) {
        return a.back < b.back;
    } else {
        return a.cnt < b.cnt;
    }
}

//����һ�����������������
int getback(string s) {
    int n = s.length();
    int back = 0;
    int count_a = 0, count_c = 0, count_g = 0, count_t = 0;
    for (int i = n - 1; i >= 0; i--) {
        switch (s[i]) {
            case 'A':
                count_a++;
                break;
            case 'C':
                count_c++;
                back += count_a;
                break;
            case 'G':
                count_g++;
                back += count_a + count_c;
                break;
            case 'T':
                count_t++;
                back += count_a + count_c + count_g;
                break;
        }
    }
    return back;
}

int main() {
    int n, m; //n��ʾ�ַ������ȣ�m��ʾ�ַ�������
    cin >> n >> m;
    DNA dna[105]; //����һ������洢DNA�ṹ��
    for (int i = 0; i < m; i++) {
        cin >> dna[i].str; //�����ַ���
        dna[i].cnt = i; //��¼�������
        dna[i].back = getback(dna[i].str); //�����������
    }
    sort(dna, dna + m, cmp); //����
    for (int i = 0; i < m; i++) {
        cout << dna[i].str << endl; //������
    }
    return 0;
}


/*
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    string s;     //��
    int log;     //�������
    int rank;    //�������
};
bool cmp(node a, node b)
{
    if (a.log != b.log)   return a.log < b.log;
    else  return a.rank < b.rank;
}
int main()
{
    int n,m;    //nΪ�ַ������ȣ�mΪ�ַ�������
    cin >> n >> m;
    vector<node>Dstr(m);
    //���뼰��ʼ��
    for (int i = 0; i < m; i++)
    {
        cin >> Dstr[i].s;   //����ÿһ���ַ���
        Dstr[i].log = 0;    //���������ʼ��Ϊ0
        Dstr[i].rank = i;
    }
    //�����������
    for (int i = 0; i < m; i++)
    {
        int countA = 0, countC = 0, countG = 0, countT = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            switch (Dstr[i].s[j])
            {
            case 'A':
                countA += 1;
                break;
            case 'C':
                countC += 1;
                Dstr[i].log += countA;
                break;
            case 'G':
                countG += 1;
                Dstr[i].log += countA + countC;
                break;
            case 'T':
                countT += 1;
                Dstr[i].log += countA + countC + countG;
                break;
            }
        }
    }
    //����
    sort(Dstr.begin(), Dstr.end(), cmp);
    for (int i = 0; i < m; i++)
        cout << Dstr[i].s << endl;
}
*/