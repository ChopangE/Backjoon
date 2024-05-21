#include<iostream>
#include<vector>
#include<deque>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> place(501, vector<int>(501, 0));
	vector<vector<bool>> visit(501, vector<bool>(501, 0));

	int N,M;
	int x1, y1, x2, y2;
	cin >> N;
	for ( int i = 0; i < N; i++ ) {
		cin >> x1 >> y1 >> x2 >> y2;
		int s_x = min(x1, x2);
		int f_x = max(x1, x2);
		int s_y = min(y1, y2);
		int f_y = max(y1, y2);
		for ( int j = s_y; j <= f_y; j++ ) {
			for ( int k = s_x; k <= f_x; k++ ) {
				place[j][k] = 1;
			}
		}
	}
	cin >> M;
	for ( int i = 0; i < M; i++ ) {
		cin >> x1 >> y1 >> x2 >> y2;
		int s_x = min(x1, x2);
		int f_x = max(x1, x2);
		int s_y = min(y1, y2);
		int f_y = max(y1, y2);
		for ( int j = s_y; j <= f_y; j++ ) {
			for ( int k = s_x; k <= f_x; k++ ) {
				place[j][k] = 2;
			}
		}
	}

	deque<iii> dq;
	dq.push_front(iii{ {0,0},0 });
	visit[0][0] = 1;
	while ( !dq.empty() ) {
		iii &t = dq.front();
		int y = t.first.first;
		int x = t.first.second;
		int w = t.second;
		dq.pop_front();
		if ( y == 500 && x == 500 ) {
			cout << w << endl;
			return 0;
		}
		for ( int i = 0; i < 4; i++ ) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			if ( nextY > 500 || nextY < 0 || nextX > 500 || nextX < 0 || visit[nextY][nextX] || place[nextY][nextX] == 2 )continue;
			if ( place[nextY][nextX] == 0 ) {
				visit[nextY][nextX] = 1;
				dq.push_front({ {nextY,nextX}, w });
			}
			else if ( place[nextY][nextX] == 1 ) {
				visit[nextY][nextX] = 1;
				dq.push_back({ {nextY,nextX}, w + 1 });
			}
		}

	}

	cout << -1 << endl;

	return 0;
}