#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> result(N, -1);
	for ( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}
	stack<ii> st;
	st.push(ii{ 0,A[0] });
	for ( int i = 1; i < N; i++ ) {
		while ( !st.empty() && st.top().second < A[i] ) {
			result[st.top().first] = A[i];
			st.pop();
		}
		st.push(ii{ i,A[i] });
	}
	for(int i = 0; i < N; i++){
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}