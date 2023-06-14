#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//定义一个结构体存储DNA字符串和逆序对数
struct DNA {
    string str;
    int back;
    int cnt; //输入次序
};

//定义排序规则，按照逆序对数从小到大，相同的按照输入次序
bool cmp(DNA a, DNA b) {
    if (a.back != b.back) {
        return a.back < b.back;
    } else {
        return a.cnt < b.cnt;
    }
}

//定义一个函数计算逆序对数
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
    int n, m; //n表示字符串长度，m表示字符串数量
    cin >> n >> m;
    DNA dna[105]; //定义一个数组存储DNA结构体
    for (int i = 0; i < m; i++) {
        cin >> dna[i].str; //输入字符串
        dna[i].cnt = i; //记录输入次序
        dna[i].back = getback(dna[i].str); //计算逆序对数
    }
    sort(dna, dna + m, cmp); //排序
    for (int i = 0; i < m; i++) {
        cout << dna[i].str << endl; //输出结果
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
    string s;     //串
    int log;     //逆序对数
    int rank;    //输入次序
};
bool cmp(node a, node b)
{
    if (a.log != b.log)   return a.log < b.log;
    else  return a.rank < b.rank;
}
int main()
{
    int n,m;    //n为字符串长度，m为字符串数量
    cin >> n >> m;
    vector<node>Dstr(m);
    //输入及初始化
    for (int i = 0; i < m; i++)
    {
        cin >> Dstr[i].s;   //输入每一行字符串
        Dstr[i].log = 0;    //逆序对数初始化为0
        Dstr[i].rank = i;
    }
    //计算逆序对数
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
    //排序
    sort(Dstr.begin(), Dstr.end(), cmp);
    for (int i = 0; i < m; i++)
        cout << Dstr[i].s << endl;
}
*/