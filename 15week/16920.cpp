#include<iostream>
#include<vector>
#include<cctype>
#include<queue>
#include<tuple>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int N, M, P;

vector<int> S;
vector<int> res;
typedef pair<int, int> ii;

queue<ii> queVec[10];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> P;
	S.resize(P + 1);
	res.resize(P + 1,0);
	vector<vector<int>> place(N, vector<int>(M));
	
	for (int i = 1; i < P + 1; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch;
			cin >> ch;
			if (isdigit(ch)) {
				place[i][j] = ch - '0';
				queVec[place[i][j]].push({ i,j });
				res[place[i][j]]++;
			}
			else if (ch == '.') {
				place[i][j] = 0;
			}
			else {
				place[i][j] = -1;
			}
		}
	}

	
	while(1){
		int count = 0;
		for (int i = 1; i < P + 1; i++) {
			int cnt = S[i];
			queue<ii>& que = queVec[i];
			if (que.empty()) {
				count++;
				continue;
			}
			for (int j = 0; j < cnt; j++) {
				int que_size = que.size();
				if (que_size == 0)break;
				while (que_size > 0) {
					int y, x;
					tie(y,x) = que.front();
					
					que.pop();
					que_size--;
					for (int k = 0; k < 4; k++) {
						int nextY = dy[k] + y;
						int nextX = dx[k] + x;
						if (nextX >= M || nextY >= N || nextY < 0 || nextX < 0 || place[nextY][nextX] != 0)continue;
						place[nextY][nextX] = i;
						res[i]++;
						que.push({ nextY,nextX });
					}
				}
			}
		}
		if (count == P)break;

	}
	for (int i = 1; i < P + 1; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}