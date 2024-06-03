#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int S;
	cin >> S;
	vector<vector<bool>> visit(2 * S + 1, vector<bool>(2 * S + 1, 0));
	queue<tuple<int, int, int>> que;
	que.push({ 1,0,0 });
	while ( !que.empty() ) {
		int now, capture, time;
		tie(now, capture, time) = que.front();
		que.pop();
		if ( now == S ) {
			cout << time << endl;
			return 0;
		}
		if ( now > 0 && now < 2 * S + 1 ) {
			if ( !visit[now][now] ) {
				que.push({ now,now,time + 1 });
				visit[now][now] = 1;
			}
			if ( !visit[now - 1][capture] ) {
				que.push({ now - 1,capture,time + 1 });
				visit[now - 1][capture] = 1;
			}
		}
		if ( capture > 0 && capture + now < 2 * S + 1 ) {
			if ( !visit[now + capture][capture] ) {
				que.push({ now + capture,capture, time + 1 });
				visit[now + capture][capture] = 1;
			}
		}
	}
	return 0;
}