#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> ii;

struct cmp {
	bool operator()(ii &a, ii &b) {
		return a.first < b.first;
	}
};

vector<int> day(10001, 0);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<ii,vector<ii>, cmp> que;		//우선순위 큐. P의 내림차순으로 정렬
	for ( int i = 0; i < n; i++ ) {
		int p, d;
		cin >> p >> d;
		que.push({ p,d });
	}
	int sum = 0;
	while ( !que.empty() ) {
		int p = que.top().first;
		int d = que.top().second;
		que.pop();
		for ( int i = d; i >= 1; i-- ) {					
			if ( day[i] == 0 ) {			//해당 날보다 이전 날들을 탐색해서 빈 날이 있으면 그날로 결정
				day[i] = p;					//해당 날짜 마킹
				sum += p;					//총 합에 더해줌
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}