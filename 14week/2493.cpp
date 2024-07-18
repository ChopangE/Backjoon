#include<iostream>
#include<vector>
#include<stack>

using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N + 1, 0);
	vector<int> res(N + 1, 0);
	for (int i = 1; i < N + 1; i++) {
		cin >> arr[i];
	}
	stack<ii> sta;
	for (int i = N; i > 0; i--) {
		while (!sta.empty() && sta.top().first < arr[i]) {
			int t = sta.top().first;
			int idx = sta.top().second;
			res[idx] = i;
			sta.pop();
		}
		sta.push({ arr[i],i });

	}
	for (int i = 1; i < N + 1; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");


	return 0;
}