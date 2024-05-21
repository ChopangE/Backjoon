#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

bool CMP(iii &a, iii &b) {
	return a.first < b.first;
}

int Find(vector<int>&s, int x) {
	if ( s[x] == -1 )return x;
	return s[x] = Find(s, s[x]);
}

bool Union(vector<int> &s, int x, int y) {
	int s_x = Find(s, x);
	int s_y = Find(s, y);
	if ( s_x == s_y ) return false;
	if ( s_x < s_y ) s[s_y] = s_x;
	else s[s_x] = s_y;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int V, E;
	cin >> V >> E;
	vector<iii> arr(E);
	vector<int> s(V + 1, -1);
	for ( int i = 0; i < E; i++ ) {
		int A, B, C;
		cin >> A >> B >> C;
		arr[i] = iii{ C,{A,B} };
	}
	sort(arr.begin(), arr.end(), CMP);
	int sum = 0;
	for ( int i = 0; i < E; i++ ) {
		iii &a = arr[i];
		if ( Union(s, a.second.first, a.second.second) ) {
			sum += a.first;
		}
	}
	cout << sum << endl;
	return 0;
}