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
        // ���� complement �Ƿ��� map ��
        if (map.find(complement) != map.end()) 
        {
            // �ҵ�������������������
            result.push_back(map[complement]);
            result.push_back(i + 1);  // �±�� 1 ��ʼ
            break;
        }
        // ����ǰ������ map ��
        map[nums[i]] = i + 1;  // �±�� 1 ��ʼ
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
	int n, a[500 + 5], key;//a�����洢n��������key��ʾ��Ҫ�ҵ�����;
	cin >> n;
	for (int i = 1; i <= n; i++)//¼��n������; 
		cin >> a[i];
	cin >> key;//����ҪѰ�ҵ����� 
	for (int i = 1; i < n; i++)//Ѱ�ҵ�һ������ 
	{
		for (int j = i + 1; j <= n; j++)//Ѱ�ҵڶ������� 
		{
			if (a[i] + a[j] == key)
			{
				cout << i << " " << j;//�ҵ��� �������������; 
				return 0;
			}
		}
	}
	return 0;
}