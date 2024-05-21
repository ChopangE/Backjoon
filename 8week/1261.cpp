#include<iostream>
#include<vector>
#include<deque>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int M, N;
	cin >> M>> N;
	vector<vector<char>> place(N, vector<char>(M));
	vector<vector<bool>> visit(N, vector<bool>(M, 0));
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < M; j++ ) {
			cin >> place[i][j];
		}
	}
	deque<iii> dq;
	dq.push_front(iii{ {0,0},0 });
	while ( !dq.empty() ) {
		int y = dq.front().first.first;
		int x = dq.front().first.second;
		int w = dq.front().second;
		dq.pop_front();
		if ( y == N - 1 && x == M - 1 ) {
			cout << w << endl;
			return 0;
		}

		for ( int i = 0; i < 4; i++ ) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			if ( (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) || visit[nextY][nextX] )continue;
			if ( place[nextY][nextX] == '0' ) {
				visit[nextY][nextX] = 1;
				dq.push_front(iii{ {nextY,nextX }, w});
			}
			else {
				visit[nextY][nextX] = 1;
				dq.push_back(iii{ {nextY,nextX }, w + 1 });
			}
		}

	}

	return 0;
}