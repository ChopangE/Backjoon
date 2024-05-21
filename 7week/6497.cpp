#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



struct tri {
	int x, y, z;
};


bool cmp(tri &a, tri &b) {
	return a.z < b.z;
}

int Find(vector<int> &s, int x) {
	if ( s[x] == -1 )return x;

	return s[x] = Find(s, s[x]);

}

bool Union(vector<int> &s, int x, int y) {
	int s_x = Find(s, x);
	int s_y = Find(s, y);

	if ( s_x == s_y )return 0;

	if ( s_x < s_y )s[s_y] = s_x;
	else s[s_x] = s_y;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	vector<int> res;
	int m, n;
	int total;
	while ( 1 ) {
		cin >> m >> n;
		total = 0;
		if ( m == 0 && n == 0 )break;
		vector<tri> adj(n);
		vector<int> s(m, -1);
		for ( int i = 0; i < n; i++ ) {
			int x, y, z;
			cin >> x >> y >> z;
			adj[i] = tri{ x,y,z };
			total += z;
		}	

		sort(adj.begin(), adj.end(), cmp);
		int tmp = 0;
		for ( int i = 0; i < n; i++ ) {
			int a, b, c;
			tri &x = adj[i];
			a = x.x;
			b = x.y;
			c = x.z;
			if ( Union(s, a, b) ) {
				tmp += c;
			}
		}
		total = total - tmp;
		res.emplace_back(total);
	}

	for ( int i = 0; i < res.size(); i++ ) {
		printf("%d\n", res[i]);
	}

	return 0;
}