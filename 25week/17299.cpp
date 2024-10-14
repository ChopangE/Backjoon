#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
using namespace std;

typedef pair<int, int> ii;

stack<ii> sta;
map<int, int> m;
vector<int> arr;
vector<int> res;
vector<int> arr2;
int N;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr.resize(N);
	res.resize(N);
	int max_ = 0;
	for ( int i = 0; i < N; i++ )
	{
		cin >> arr[i];
		max_ = max(max_, arr[i]);
	}
	arr2.resize(max_ + 1, 0);
	for ( int i = 0; i < N; i++ )
	{
		arr2[arr[i]]++;
	}
	for ( int i = 0; i < N; i++ )
	{
		int a = arr2[arr[i]];

		if ( sta.empty() || arr2[sta.top().second] >= a )
		{
			sta.push({ i, arr[i] });
		}
		else
		{
			while ( !sta.empty() && arr2[sta.top().second] < a )
			{
				res[sta.top().first] = arr[i];
				sta.pop();
			}
			sta.push({ i,arr[i] });
		}
	}
	while ( !sta.empty() )
	{
		ii a = sta.top();
		res[a.first] = -1;
		sta.pop();
	}

	for ( int i = 0; i < res.size(); i++ )
	{
		printf("%d ", res[i]);
	}
	printf("\n");

	return 0;
}