#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	if ( N % 2 == 1 ) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> dp(31 , 0);
	dp[2] = 3;
	dp[3] = 2;
	for ( int i = 4; i <= N; i++ ) {
		if ( i % 2 == 1 ) {
			dp[i] = dp[i - 3] * dp[3] + dp[i - 2];
		}
		else {
			dp[i] = dp[i - 2] * dp[2] + dp[i - 1];
		}
	}

	cout << dp[N] << endl;
	return 0;
}