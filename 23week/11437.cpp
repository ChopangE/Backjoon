#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>
#include<set>

using namespace std;

typedef pair<int, int> ii;

int N, M;
vector<vector<int>> adj;
vector<int> parents;
vector<int> level;

void DFS(int parent, int cur)
{
	level[cur] = level[parent] + 1;
	parents[cur] = parent;
	for ( int child : adj[cur] )
	{
		if ( child == parent )continue;
		DFS(cur, child);
	}
}

void DFS2(int cur, vector<int> &res)
{
	if ( cur == 1 )
	{
		res.push_back(1);
		return;
	}
	res.push_back(cur);
	DFS2(parents[cur], res);
}

int CheckVec(vector<int> &a, vector<int> &b)
{
	int a_idx = a.size() - 1;
	int b_idx = b.size() - 1;
	while ( a_idx >= 0 && b_idx >= 0 )
	{
		if ( a[a_idx] != b[b_idx] ) return a[a_idx + 1];
		a_idx--;
		b_idx--;
	}
	if ( b_idx < 0 ) return b[0];
	else return a[0];
}

int Check(int a, int b)
{
	if ( level[a] < level[b] )
	{
		while ( level[a] != level[b] )
		{
			b = parents[b];
		}

		while ( a != b )
		{
			a = parents[a];
			b = parents[b];
		}
		return a;
	}
	else
	{
		while ( level[a] != level[b] )
		{
			a = parents[a];
		}
		while ( a != b )
		{
			a = parents[a];
			b = parents[b];
		}
		return a;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	adj.resize(N + 1, vector<int>());
	parents.resize(N + 1,0);
	level.resize(N + 1, 0);
	for ( int i = 0; i < N - 1; i++ )
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	DFS(0, 1);
	cin >> M;
	vector<int> real;
	for ( int i = 0; i < M; i++ )
	{
		int a, b;
		cin >> a >> b;
		
		printf("%d\n",Check(a, b));
	}

	


	return 0;
}