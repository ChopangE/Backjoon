#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef pair<int, int> ii;
int M, N, L;
vector<int> gun_location;
vector<ii> ani_location;
int sum = 0;
bool diff(const int &gun, const int &ani_idx) {
	//int a = gun_location[gun_idx];
	ii b = ani_location[ani_idx];
	return abs(gun - b.first) + b.second <= L;
}	



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> L;
	gun_location.resize(M);
	ani_location.resize(N);
	for (int i = 0; i < M; i++) {
		cin >> gun_location[i];
	}
	
	sort(gun_location.begin(), gun_location.end());

	for (int i = 0; i < N; i++) {
		cin >> ani_location[i].first >> ani_location[i].second;
	}
	for (int i = 0; i < N; i++) {
		int ani_loc_x = ani_location[i].first;
		auto iter = lower_bound(gun_location.begin(), gun_location.end(), ani_loc_x);
		if (iter == gun_location.end())iter--;
		if (iter == gun_location.begin()) {
			if (diff(*iter, i)) sum++;
		}
		else {
			auto iter2 = iter - 1;
			if (abs((*iter) - ani_loc_x) > abs(*iter2- ani_loc_x)) iter = iter2;
			if (diff(*iter, i)) sum++;
		}

	}
	cout << sum << endl;
	return 0;
}