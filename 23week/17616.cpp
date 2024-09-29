#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int N, M, X;

vector<vector<int>> parents;
vector<vector<int>> childs;

int parent_num;
int child_num;

vector<bool> visit;

int DFS(vector<vector<int>> &adj, int cur)
{
	if (visit[cur]) return 0;
	visit[cur] = true;
	int sum = 0;
	for (int next : adj[cur])
	{	
		sum += DFS(adj, next);
	}
	return sum + 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X;
	parents.resize(N + 1, vector<int>());
	childs.resize(N + 1, vector<int>());
	visit.resize(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		childs[a].push_back(b);
		parents[b].push_back(a);
	}
	int front = DFS(parents, X);
	fill(visit.begin(), visit.end(), 0);
	int back = DFS(childs, X) - 1;
	cout << front << " " << N - back << endl;
	return 0;
}