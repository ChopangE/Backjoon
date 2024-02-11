#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N,S;
	cin >> N >> S;
	vector<int> arr(N);
	
	for ( int i = 0; i < N; i++ ) {
		cin >> arr[i];
	}

	int sum = 0, count = 0;
	int mincount = 100001;
	int left = 0, right = 0;
	if ( S == 0 ) {
		cout << 1 << endl;
		return 0;
	}
	while ( 1 ) {
		if ( right == N && sum < S) {
			break;
		}
		if ( sum >= S ) {
			count = right - left;
			mincount = min(mincount, count);
			if ( mincount == 1 )break;
			sum -= arr[left++];
		}

		if ( sum < S ) {
			if(right < N)
			sum += arr[right++];
		}
	}

	if ( mincount == 100001 )mincount = 0;
	cout << mincount << endl;
	return 0;
}