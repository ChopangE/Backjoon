#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, cnt = 0;

void DFS(vector<vector<int>> &place, vector<vector<bool>> &visit, int& tmp,int y,int x)
{
	tmp++;
	visit[y][x] = 1;
	for ( int i = 0; i < 4; i++ )
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if ( nx >= M || nx < 0 || ny >= N || ny < 0 || visit[ny][nx] || place[ny][nx] == 0 )continue;
		DFS(place, visit, tmp, ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	vector<vector<int>> place(N, vector<int>(M));
	vector<ii> ice;
	for ( int i = 0; i < N; i++ ) 
	{
		for ( int j = 0; j < M; j++ ) 
		{
			cin >> place[i][j];
			if ( place[i][j] > 0 ) 
			{
				cnt++;
				ice.push_back({ i,j });
			}
		}
	}
	int Time = 0;
	int cc = 0;
	bool isCheck = 0;
	while ( cc < 25000)
	{
		Time++;
		vector<ii> check;
		for ( int i = 0; i < ice.size(); i++ )
		{
			ii &cur = ice[i];
			if ( place[cur.first][cur.second] == 0 )continue;
			for ( int j = 0; j < 4; j++ )
			{
				int ny = cur.first + dy[j];
				int nx = cur.second + dx[j];
				if ( nx < 0 || nx >= M || ny >= N || ny < 0 || place[ny][nx] != 0 )continue;
				place[cur.first][cur.second]--;
			}
			if ( place[cur.first][cur.second] <= 0 )
			{
 				place[cur.first][cur.second] = -1;
				check.push_back(cur);
				cnt--;
			}
			
		}
		for ( ii &c : check )
		{
			place[c.first][c.second] = 0;
		}

		int tmp = 0;
		vector<vector<bool>> visit(N, vector<bool>(M, 0));
		for ( int i = 0; i < ice.size(); i++ )
		{
			ii &cur = ice[i];
			if ( place[cur.first][cur.second] > 0 )
			{
				DFS(place, visit, tmp, cur.first, cur.second);
				break;
			}
		}
		if ( tmp != cnt )
		{
			
			isCheck = 1;
			break;
		}
		cc++;
	}
	if ( isCheck )
	{
		cout << Time << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;

}