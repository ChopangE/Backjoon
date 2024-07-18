#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, H;
	cin >> N >> H;
	//vector<int> obstacle(N);
	vector<long long> height(H);
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (i % 2 == 0) {
			height[0] += 1;
			if(t < H) height[t] += -1;
		}
		else {
			height[H - t] += 1;
		}
	}
	
	for (int i = 1; i < H; i++) {
		height[i] += height[i - 1];
	}
	int min_num = 200001;
	int count = 0;
	for (int i = 0; i < H; i++) {
		if (height[i] < min_num) {
			count = 1;
			min_num = height[i];
		}
		else if (height[i] == min_num) {
			count++;
		}
	}

	cout << min_num << " " << count << endl;

	return 0;
}