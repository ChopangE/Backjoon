#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>
#include<cmath>
using namespace std;

typedef pair<int, int> ii;

int N;
vector<int> people;
vector<int> idx;
vector<vector<int>> adj;
int sum = 0;
int total = 10000;
bool BFS(vector<int>& res)
{
	vector<int> visit(N + 1, 0);
	for ( int i : res )
	{
		visit[i] = 1;
	}
	queue<int> que;
	que.push(res[0]);
	visit[res[0]] = 2;
	int t = res.size();
	while ( !que.empty() )
	{
		int x = que.front();
		que.pop();
		t--;
		for ( int ad : adj[x] )
		{
			if ( visit[ad] == 1 )
			{
				visit[ad] = 2;
				que.push(ad);
			}
		}
	}
	if ( t == 0 )
	{
		// 나머지 연결 확인
		for ( int i = 1; i < N+1; i++ )
		{
			if ( visit[i] == 0 )
			{
				que.push(i);
				visit[i] = 2;
				break;
			}
		}
		int k = N - res.size();
		while ( !que.empty() )
		{
			int x = que.front();
			que.pop();
			k--;
			for ( int ad : adj[x] )
			{
				if ( visit[ad] == 0 )
				{
					que.push(ad);
					visit[ad] = 2;
				}
			}
		}
		return k == 0;
	}
	else
	{
		return false;
	}

}

int Sum(vector<int> &res)
{
	int sum = 0;
	for ( int i : res )
	{
		sum += people[i];
	}
	return sum;
}
void BackTrack(vector<int> &res, int i)
{
	if ( i == N + 1 )
	{
		if ( res.size() == 0 || res.size() == N )return;
		if ( BFS(res) )
		{
			int s = Sum(res);
			total = min(total, abs((sum - s) - s));
		}
		return;
	}
	for ( int j = 0; j < 2; j++ )
	{
		if ( j == 0 )
		{
			res.push_back(i);
			BackTrack(res, i + 1);
			res.pop_back();
		}
		else
		{
			BackTrack(res, i + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	people.resize(N + 1);
	adj.resize(N + 1);
	for ( int i = 1; i < N + 1; i++ )
	{
		cin >> people[i];
		sum += people[i];
	}
	for ( int i = 1; i < N + 1; i++ )
	{
		int T;
		cin >> T;
		for ( int j = 0; j < T; j++ )
		{
			int t;
			cin >> t;
			adj[i].push_back(t);
		}
	}
	vector<int> res;
	BackTrack(res, 1);
	if ( total == 10000 )cout << -1 << endl;
	else cout << total << endl;
	return 0;
}