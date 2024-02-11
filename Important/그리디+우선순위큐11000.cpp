#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> ii;

bool CMP(ii &a, ii &b) {
	if ( a.first == b.first ) return a.second > b.second;
	return a.first < b.first;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<ii> array(N);
	priority_queue<int, vector<int>, greater<int>> que;
	for ( int i = 0; i < N; i++ ) {
		int t1, t2;
		cin >> t1 >> t2;
		array[i].first = t1;
		array[i].second = t2;
	}
	sort(array.begin(), array.end());
	for ( int i = 0; i < N; i++ ) {
		que.push(array[i].second);
		if ( que.top() <= array[i].first )que.pop();
	}

	cout << que.size() << endl;

	return 0;
}