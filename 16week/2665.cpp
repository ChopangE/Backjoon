#include<iostream>
#include<vector>
#include<deque>
#include<tuple>
using namespace std;

typedef pair<int, int> ii;
//typedef pair<int, ii> iii;
typedef tuple<int, int, int> iii;
vector<vector<bool>> place;
vector<vector<bool>> visit;
int n;
deque<iii> dq;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	place.resize(n);
	visit.resize(n);
	for ( int i = 0; i < n; i++ ) {
		place[i].resize(n);
		visit[i].resize(n, 0);
	}
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			char t;
			cin >> t;
			if ( t == '1' ) {
				place[i][j] = 1;
			}
			else {
				place[i][j] = 0;
			}
		}
	}
	dq.push_front(iii{ 0,0,0 });
	visit[0][0] = 1;
	while ( !dq.empty() ) {
		int y, x, t;
		tie(y, x, t) = dq.front();
		if ( y == n - 1 && x == n - 1 ) {
			cout << t << endl;
			return 0;
		}
		dq.pop_front();
		for ( int i = 0; i < 4; i++ ) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ( nx >= n || ny >= n || nx < 0 || ny < 0 || visit[ny][nx] )continue;
			if ( place[ny][nx] ) {
				visit[ny][nx] = 1;
				dq.push_front({ ny,nx,t });
			}
			else {
				visit[ny][nx] = 1;
				dq.push_back({ ny,nx,t + 1 });
			}
		}


	}
	return 0;
}