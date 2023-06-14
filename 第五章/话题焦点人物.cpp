#include <iostream>
#include <algorithm>

using namespace std;
struct people {
    int have = 0;
    int all[10010];
} p[101];

int main() {
    int n;
    cin >> n;
    int name;
    int num, temp;
    for (int i = 0; i < n; ++i) {//输入
        cin >> name >> num;
        for (int j = 0; j < num; ++j) {
            cin >> temp;
            p[temp].all[p[temp].have] = name;
            p[temp].have++;
        }
    }
    int max = 0;
    for (int i = 1; i <= 100; ++i) {//找最大
        if (p[i].have > p[max].have) {
            max = i;
        }
    }
    cout << max << endl;
    sort(p[max].all, p[max].all + p[max].have);
    for (int i = 0; i < p[max].have; ++i) {

        cout << p[max].all[i] << " ";
        while (p[max].all[i] == p[max].all[i + 1])i++;//去重
    }

}
