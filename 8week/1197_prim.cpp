#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

//bool CMP(iii &a, iii &b) {
//	return a.first < b.first;
//}

struct cmp {

	bool operator()(ii &a, ii &b) {
		return a.second > b.second;
	}
};
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
	vector<vector<ii>> arr(V + 1, vector<ii>());
	vector<bool> visit(V + 1, 0);
	vector<int> s(V + 1, -1);
	for ( int i = 0; i < E; i++ ) {
		int A, B, C;
		cin >> A >> B >> C;
		arr[A].emplace_back(ii{ B,C });
		arr[B].emplace_back(ii{ A,C });
	}
	priority_queue<ii, vector<ii>, cmp> pq;
	visit[1] = 1;
	for ( ii &a : arr[1] ) {
		pq.push(a);
	}
	int sum = 0;
	while ( !pq.empty() ) {
		int cur, w;
		cur = pq.top().first;
		w = pq.top().second;
		pq.pop();
		if ( visit[cur] )continue;
		visit[cur] = 1;
		sum += w;
		for ( ii &next : arr[cur] ) {
			if ( visit[next.first] )continue;
			pq.push(next);
		}

	}
	cout << sum << endl;
	return 0;
}