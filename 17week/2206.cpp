#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

typedef tuple<int, int, int> iii;


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<char>> place(N, vector<char>(M));
	vector<vector<vector<int>>> count(2, vector<vector<int>>(N, vector<int>(M,-1)));
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < M; j++ ) {
			cin >> place[i][j];
		}
	}
	queue<iii> que;
	que.push({ 0,0,0 });
	count[0][0][0] = 1;
	while ( !que.empty() ) {
		int y, x, t;
		tie(y, x, t) = que.front();
		que.pop();
		for ( int i = 0; i < 4; i++ ) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if ( ny >= N || ny < 0 || nx >= M || nx < 0 )continue;
			if ( t == 0 ) {
				if ( place[ny][nx] == '1' && count[1][ny][nx] == -1) {
					count[1][ny][nx] = count[t][y][x] + 1;
					que.push({ ny,nx,1 });
				}
				else if ( place[ny][nx] == '0' && count[0][ny][nx] == -1 ) {
					count[0][ny][nx] = count[t][y][x] + 1;
					que.push({ ny,nx,0 });
				}
			}
			else {
				if ( place[ny][nx] == '0' && count[1][ny][nx] == -1 ) {
					count[1][ny][nx] = count[t][y][x] + 1;
					que.push({ ny,nx, 1 });
				}
			}
		}
		
	}

	if ( count[0][N - 1][M - 1] == -1 ) {
		cout << count[1][N - 1][M - 1] << endl;
	}
	else {
		if ( count[1][N - 1][M - 1] == -1 ) cout << count[0][N - 1][M - 1] << endl;
		else {
			cout << min(count[1][N - 1][M - 1], count[0][N - 1][M - 1]) << endl;
		}
	}


	return 0;

}