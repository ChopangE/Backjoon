#include<iostream>
#include<vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> sum(N, 0);
	cin >> sum[0];
	for (int i = 1; i < N; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	int left, right;
	int totalsum = 0;
	//양 끝점에 있을 때.
	left = 0;
	right = N - 1;
	int tmp = sum[N-2] - sum[0];
	int m = 0;
	for (int i = 1; i < N - 1; i++) {
		int t = sum[i] - sum[i - 1];
		m = max(t, m);
	}
	totalsum = tmp + m;
	//한 쪽에 몰려있을 때.
	//왼쪽
	for (int i = 1; i < N - 1; i++) {
		int a = sum[i - 1] - sum[0];
		int b = sum[N - 1] - sum[i];
		tmp = a + 2 * b;
		totalsum = max(totalsum, tmp);
	}
	for (int i = N - 2; i > 0; i--) {
		int a = sum[N - 2] - sum[i];
		int b = sum[i-1];
		tmp = a + 2 * b;
		totalsum = max(totalsum, tmp);
	}
	/*int a = (sum[2] - sum[1]) * 2;
	int b = sum[1] - sum[0];
	if (b > a) {
		tmp = b + (sum[N - 1] - sum[2]) * 2;
		totalsum = max(tmp, totalsum);
	}
	else {
		tmp = (sum[N - 1] - sum[1]) * 2;
		totalsum = max(tmp, totalsum);
	}
	cout << totalsum << endl;

	a = (sum[N - 3] - sum[N-4]) * 2;
	b = sum[N - 2] - sum[N - 3];
	if (b > a) {
		tmp = b + sum[N - 4] * 2;
		totalsum = max(tmp, totalsum);
	}
	else {
		tmp = sum[N - 3] * 2;
		totalsum = max(tmp, totalsum);
	}*/
	cout << totalsum << endl;
	return 0;
}