#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, M;

int totalSum = 0;
int tmp = 0;

bool CheckFill(vector<vector<bool>> &visit,int y, int x, int num, bool dx) {
	for (int i = 0; i <= num; i++) {
		if (dx) {
			int next = x + i;
			if (next >= M || visit[y][next])return false;
		}
		else {
			int next = y + i;
			if (next >= N || visit[next][x])return false;
		}
	}
	return true;
}

int Fill(vector<vector<bool>> &visit, vector<vector<int>>& place, int i, int y, int x, bool dx,bool check) {
	if (i < 0)return 0;
	visit[y][x] = check;
	if (dx) {
		return place[y][x] * pow(10, i) + Fill(visit, place, i - 1, y, x + 1, dx,check);
	}
	else {
		return place[y][x] * pow(10, i) + Fill(visit, place, i - 1, y + 1, x, dx,check);
	}
	
}

bool checkAll(vector<vector<int>>&place, vector<vector<bool>>& visit, int &nextY, int& nextX) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]) {
				nextY = i;
				nextX = j;
				return false;
			}
		}
	}
	return true;
}
void BackTrack(vector<vector<int>> &place, vector<vector<bool>> &visit,int y, int x) {
	int nextY = 0, nextX = 0;
	for (int i = 0; i < M; i++) {
		if (!CheckFill(visit, y, x, i, 1))continue;
		
		tmp += Fill(visit, place, i, y, x , 1,1);
		if (checkAll(place, visit, nextY, nextX)) {
			totalSum = max(totalSum, tmp);
			tmp -= Fill(visit, place, i, y, x, 1, 0);
		}
		else {
			BackTrack(place, visit, nextY, nextX);
			tmp -= Fill(visit, place, i, y, x, 1, 0);
		}
		
	}
	for (int i = 0; i < N; i++) {
		if (!CheckFill(visit, y, x, i, 0))continue;
		tmp += Fill(visit, place, i, y, x, 0, 1);
		if (checkAll(place, visit, nextY, nextX)) {
			totalSum = max(totalSum, tmp);
			tmp -= Fill(visit, place, i, y, x, 0, 0);
		}
		else {
			BackTrack(place, visit, nextY, nextX);
			tmp -= Fill(visit, place, i, y, x, 0, 0);
		}
	}


}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	vector<vector<int>> place(N,vector<int>(M));
	vector<vector<bool>> visit(N, vector<bool>(M,0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char tmp;
			cin >> tmp;
			place[i][j] = tmp - '0';
		}
	}

	BackTrack(place, visit, 0, 0);

	cout << totalSum << endl;

	return 0;
}