#include<iostream>
#include<cstring>
#include<algorithm> 
#include<stack>
using namespace std;

stack<char> s1;		//�����ջ 
stack<char> s2;		//�м���ջ 

int f(const char str) {
	int yxj;		//���ȼ� 
	switch (str) {
	case '*':yxj = 5; break;
	case '/':yxj = 5; break;
	case '+':yxj = 4; break;
	case '-':yxj = 4; break;
	}
	return yxj;
}
int main() {
	//char c[100] = "(12+4-13)+6*2";
	char c[100]="1+((2+3)*4)-5";
	int lenc = strlen(c);
	//��ȡ�ַ��� 
	for (int i = 0; i < lenc; i++) {
		if (c[i] >= '0' && c[i] <= '9') {		//��������֣�ֱ��ѹ��s2 
			s2.push(c[i]);
		}
		else if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/') {	//���������� 
			while (true) {
				if (s1.empty() || s1.top() == '(') {		//s1Ϊ�� ������ջ��Ϊ( 
					s1.push(c[i]);
					break;
				}
				else if (f(c[i]) > f(s1.top())) {		//��ǰ��������ȼ�����s1ջ����������ȼ� 
					s1.push(c[i]);
					break;
				}
				else {								//С�ڵ��� 
					char cc = s1.top();
					s1.pop();
					s2.push(cc);
				}
			}
		}
		else {
			if (c[i] == '(') {			//ֱ�Ӷ��� 
				s1.push(c[i]);
			}
			else {
				while (s1.top() != '(') {
					char ccc = s1.top();
					s1.pop();
					s2.push(ccc);
				}
				s1.pop();
			}
		}
	}
	while (!s1.empty()) {
		char cccc = s1.top();
		s2.push(cccc);
		s1.pop();
	}

	//while(!s2.empty()){	//���������� 
	//	cout<<s2.top();
	//	s2.pop();
	//}
	while (!s2.empty()) {
		char c = s2.top();
		s1.push(c);
		s2.pop();
	}
	while (!s1.empty()) {
		cout << s1.top();
		s1.pop();
	}

	return 0;
}