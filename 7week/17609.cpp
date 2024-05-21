#include<iostream>
#include<vector>
#include<string>

using namespace std;

int check(string &str, int s, int e, bool isLast) {
	int left = s;
	int right = e;
	int isCheck = 0;
	while ( left < right ) {

		if ( str[left] != str[right] ) {
			//cout << str[left]<< " " << str[right] << endl;
			if ( isLast == 0 ) {
				int a1 = check(str, left + 1, right,1);
				int a2 = check(str, left, right - 1,1);
				/*cout << "a1 : " << a1 << endl;
				cout << "a2 : " << a2 << endl;*/

				if ( a1 == 0 || a2 == 0 ) {
					isCheck = 1;
				}
				else {
					isCheck = 2;
				}
				break;
			}
			else {
				isCheck = 2;
				break;
			}
			
		}
		left++;
		right--;
	}
	return isCheck;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for ( int i = 0; i < T; i++ ) {
		string str;
		cin >> str;
		cout << check(str,0,str.size()-1 ,0) << endl;
	}

	return 0;
}