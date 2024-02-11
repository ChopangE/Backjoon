#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*

가장 긴 증가하는 수열 만드는 방법
nlogn시간으로 작성하기.

*/

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> result;
	for ( int i = 0; i < N; i++ ) {
		cin >> arr[i];
	}
	result.emplace_back(arr[0]);
	for ( int i = 1; i < N; i++ ) {
		if ( result.back() < arr[i] )result.emplace_back(arr[i]);
		else {
			int idx = lower_bound(result.begin(), result.end(), arr[i]) - result.begin();
			result[idx] = arr[i];
		}
	}
	cout << result.size() << endl;



	return 0;
}