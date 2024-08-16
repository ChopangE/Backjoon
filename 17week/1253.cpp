#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<bool> good(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {
		int target = A[i];
		int left = 0;
		int right = N - 1;
		while (left < right) {
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}
			if (A[left] + A[right] > target) {
				right--;
			}
			else if (A[left] + A[right] < target) {
				left++;
			}
			else {
				good[i] = true;
				break;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (good[i])sum++;
	}
	cout << sum << endl;
	return 0;
}