#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int H, W;
	cin >> H >> W;
	vector<int> rains(W);
	for (int i = 0; i < W; i++) {
		cin >> rains[i];
	}
	int totalSum = 0;
	for (int i = 0; i < H; i++) {
		int tmpSum = 0;
		bool left = false;
		for (int j = 0; j < W; j++) {
			if (rains[j] > i) {
				if (left) {
					totalSum += tmpSum;
				}
				tmpSum = 0;
				left = true;
			}
			else {
				tmpSum++;
			}
		}
	}
	cout << totalSum << endl;
	return 0;
}