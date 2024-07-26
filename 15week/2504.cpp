#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int sum = 0;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	stack<char> sta;
	stack<int> num_sta;
	string str;
	cin >> str;
	for ( int i = 0; i < str.size(); i++ ) {
		const char &c = str[i];
		if ( c == '(' ) {

			sta.push(c);
			num_sta.push(2);
		}
		else if ( c == '[' ) {
			sta.push(c);
			num_sta.push(3);
		}
		else if ( c == ')' ) {
			if ( sta.empty() ) {
				cout << 0 << endl;
				return 0;
			}
			char top = sta.top();
			if ( top != '(' ) {
				cout << 0 << endl;
				return 0;
			}
			int top_num = num_sta.top();
			num_sta.pop();
			sta.pop();
			if ( sta.empty() ) {
				sum += top_num;

			}
			else {
				char new_top = sta.top();
				int new_num_top = num_sta.top();
				if ( new_top == '(' ) {
					num_sta.pop();
					if ( new_num_top == 2 )new_num_top = 0;
					new_num_top += top_num * 2;
					num_sta.push(new_num_top);
				}
				else if ( new_top == '[' ) {
					num_sta.pop();
					if ( new_num_top == 3 )new_num_top = 0;
					new_num_top += top_num * 3;
					num_sta.push(new_num_top);
				}
			}

		}
		else {	//  c == ']
			if ( sta.empty() ) {
				cout << 0 << endl;
				return 0;
			}
			char top = sta.top();
			if ( top != '[' ) {
				cout << 0 << endl;
				return 0;
			}
			int top_num = num_sta.top();
			num_sta.pop();
			sta.pop();
			if ( sta.empty() ) {
				sum += top_num;
			}
			else {
				char new_top = sta.top();
				int new_num_top = num_sta.top();
				if ( new_top == '(' ) {
					num_sta.pop();
					if ( new_num_top == 2 )new_num_top = 0;
					new_num_top += top_num * 2;
					num_sta.push(new_num_top);
				}
				else if ( new_top == '[' ) {
					num_sta.pop();
					if ( new_num_top == 3 )new_num_top = 0;
					new_num_top += top_num * 3;
					num_sta.push(new_num_top);
				}
			}
		}



	}
	cout << sum << endl;

	return 0;
}