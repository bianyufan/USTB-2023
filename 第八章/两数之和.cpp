/*
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> findTwoSum(vector<int>& nums, int target) 
{
    vector<int> result;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) 
    {
        int complement = target - nums[i];
        // 查找 complement 是否在 map 中
        if (map.find(complement) != map.end()) 
        {
            // 找到了满足条件的两个数
            result.push_back(map[complement]);
            result.push_back(i + 1);  // 下标从 1 开始
            break;
        }
        // 将当前数存入 map 中
        map[nums[i]] = i + 1;  // 下标从 1 开始
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> numbers[i];
    }
    int target;
    cin >> target;
    vector<int> indices = findTwoSum(numbers, target);
    cout << indices[0] << " " << indices[1] << endl;
    return 0;
}
*/
#include <iostream>
using namespace std;
int main()
{
	int n, a[500 + 5], key;//a用来存储n个整数，key表示需要找的数字;
	cin >> n;
	for (int i = 1; i <= n; i++)//录入n个数字; 
		cin >> a[i];
	cin >> key;//输入要寻找的数字 
	for (int i = 1; i < n; i++)//寻找第一个数字 
	{
		for (int j = i + 1; j <= n; j++)//寻找第二个数字 
		{
			if (a[i] + a[j] == key)
			{
				cout << i << " " << j;//找到后 输出并结束程序; 
				return 0;
			}
		}
	}
	return 0;
}