#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int N, M;
vector<vector<int>> parents;
vector<vector<int>> childs;

vector<int> parent_num;
vector<int> child_num;
vector<bool> visit;

int DFS(int cur, vector<vector<int>> &arr)
{
	if (visit[cur]) return 0;
	visit[cur] = 1;
	int sum = 0;
	for (int next : arr[cur])
	{
		sum += DFS(next, arr);
	}
	return sum + 1;
}



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	parents.resize(N + 1, vector<int>());
	childs.resize(N + 1, vector<int>());
	parent_num.resize(N + 1, -1);
	child_num.resize(N + 1, -1);
	visit.resize(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		childs[a].push_back(b);
		parents[b].push_back(a);
	}

	for (int i = 1; i < N + 1; i++)
	{
		parent_num[i] = DFS(i, parents) - 1;
		fill(visit.begin(), visit.end(), 0);
		child_num[i] = DFS(i, childs) - 1;
		fill(visit.begin(), visit.end(), 0);
	}

	for (int i = 1; i < N + 1; i++)
	{
		printf("%d\n", (N - 1) - (child_num[i] + parent_num[i]));
	}
	return 0;
}