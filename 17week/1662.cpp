#include<iostream>
#include<vector>
#include<cctype>
#include<stack>

using namespace std;

string str;
stack<int> sta;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	int t;
	sta.push(0);
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i])) {
			t = sta.top();
			sta.pop();
			sta.push(t + 1);
		}
		else if (str[i] == '(') {
			t = sta.top();
			sta.pop();
			sta.push(t - 1);			//������� ��������
			sta.push(str[i - 1] - '0');	//���ϱ� ����Ұ�
			sta.push(0);				//���ο� ����
		}
		else {
			t = sta.top();
			sta.pop();
			int k = sta.top();
			sta.pop();
			int u = sta.top();
			sta.pop();
			sta.push(u + t * k);
		}
	}


	cout << sta.top() << endl;


	return 0;
}