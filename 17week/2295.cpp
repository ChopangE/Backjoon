#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N);
	set<int> s;
	for ( int i = 0; i < N; i++ ) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for ( int i = 0; i < N; i++ ) {
		for ( int j = i; j < N; j++ ) {
			s.insert(arr[i] + arr[j]);
		}
	}
	
	for ( int i = N - 1; i >= 0; i-- ) {
		int target = arr[i];
		for ( int j = i - 1; j >= 0; j-- ) {
			if ( s.find(target - arr[j]) != s.end() ) {
				cout << target << endl;
				return 0;
			}
		}
	}

	return 0;

}