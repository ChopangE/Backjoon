#include<iostream>
#include<vector>


using namespace std;


typedef pair<int, int> ii;

int n, m;

vector<int> good;

void DFS(vector<vector<int>> &child, int parent) {
	for (int &ch : child[parent]) {
		good[ch] += good[parent];
		DFS(child, ch);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	good.resize(n+1, 0);
	vector<vector<int>> child(n + 1, vector<int>());
	int t;
	cin >> t;
	for (int i = 2; i < n + 1; i++) {
		cin >> t;
		child[t].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		good[a] += b;
	}
	DFS(child, 1);
	for (int i = 1; i < n + 1; i++) {
		cout << good[i] << " ";
	}
	
	return 0;
}