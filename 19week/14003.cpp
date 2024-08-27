#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> res;
	vector<int> trace(N);
	stack<int> real_res;
	int idx = 1;
	for ( int i = 0; i < N; i++ )
	{
		cin >> arr[i];
	}
	res.push_back(arr[0]);
	trace[0] = idx;
	for ( int i = 1; i < N; i++ )
	{
		if ( res.back() < arr[i] )
		{
			res.push_back(arr[i]);
			trace[i] = ++idx;
		}
		else
		{
			auto iter = lower_bound(res.begin(), res.end(), arr[i]);
			int diff = (iter - res.begin());
			res[diff] = arr[i];
			trace[i] = diff + 1;
		}
	}

	for ( int i = N - 1; i >= 0; i-- )
	{
		if ( trace[i] == idx )
		{
			idx--;
			real_res.push(arr[i]);
		}
	}
	printf("%d\n", real_res.size());
	while ( !real_res.empty() )
	{
		printf("%d ", real_res.top());
		real_res.pop();
	}

	return 0;

}