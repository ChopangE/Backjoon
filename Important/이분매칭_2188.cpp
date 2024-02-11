#include<iostream>
#include<vector>

using namespace std;

bool DFS(vector<int> &cow, vector<int> &B, vector<bool> &visit, vector<vector<int>> &adj, int i) {
	visit[i] = 1;
	int size = adj[i].size();
	for ( int j = 0; j < size; j++ ) {
		int b = adj[i][j];
		if ( B[b] == -1 || !visit[B[b]] && DFS(cow, B, visit, adj, B[b]) ) {
			B[b] = i;
			return 1;
		}
	}
	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, cnt = 0;
	cin >> N >> M;

	vector<int> cow(N);
	vector<int> B(M + 1, -1);
	vector<bool> visit(N, 0);
	vector<vector<int>> adj(N, vector<int>());

	for ( int i = 0; i < N; i++ ) {
		int k;
		cin >> k;
		for ( int j = 0; j < k; j++ ) {
			int t;
			cin >> t;
			adj[i].emplace_back(t);
		}
	}
	for ( int i = 0; i < N; i++ ) {
		fill(visit.begin(), visit.end(), false);
		if ( DFS(cow, B, visit, adj, i) ) cnt++;
	}
	
	cout << cnt << endl;
	return 0;
}