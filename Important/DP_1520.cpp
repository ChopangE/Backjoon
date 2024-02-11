#include<iostream>
#include<vector>

using namespace std;
/*
void sum(vector<vector<int>> &place, vector<vector<int>> &s, int &M, int &N, int x, int y, int p) {
	s[x][y] = 0;
	if ( x - 1 >= 0 ) {
		if ( place[x - 1][y] > p )s[x][y] += s[x - 1][y];
	}
	if ( x + 1 < M ) {
		if ( place[x + 1][y] > p )s[x][y] += s[x + 1][y];
	}
	if ( y - 1 >= 0 ) {
		if ( place[x][y - 1] > p )s[x][y] += s[x][y - 1];
	}
	if ( y + 1 < N ) {
		if ( place[x][y + 1] > p )s[x][y] += s[x][y + 1];
	}
}
*/

int xx[4] = { -1, 0, 1, 0 };
int yy[4] = { 0, -1, 0, 1 };

int DFS(vector<vector<int>> &place, vector<vector<int>> &s, int &M, int &N, int x, int y) {
	if ( x == M - 1 && y == N - 1 ) return 1;
	if ( s[x][y] != -1 )return s[x][y];
	s[x][y] = 0;
	for ( int i = 0; i < 4; i++ ) {
		int nx = x + xx[i];
		int ny = y + yy[i];
		if ( nx >= 0 && nx < M && ny >= 0 && ny < N ) {

			if(place[nx][ny] < place[x][y] )
			s[x][y] = s[x][y] + DFS(place, s, M, N, nx, ny);					//s[x][y]저장 메모라이징		
		}
	}
	return s[x][y];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M, N;
	cin >> M >> N;
	
	vector<vector<int>> place(M, vector<int>(N));
	vector<vector<int>> s(M, vector<int>(N,-1));
	
	for ( int i = 0; i < M; i++ ) {
		for ( int j = 0; j < N; j++ ) {
			cin >> place[i][j];
		}
	}
	cout << DFS(place, s, M, N, 0, 0) << "\n";
	return 0;
}