#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> arr;
vector<bool> visit;
vector<int> res;
int sum = 0;
bool DFS(vector<bool>& check, int i, const int &root)
{
	check[i] = 1;
	int child = arr[i];
	if (child == root)
	{
		return true;
	}
	if (check[child])
	{
		return false;
	}
	return DFS(check, child, root);

}

void check_(int i)
{
	if (visit[i])return;
	res.push_back(i);
	sum++;
	visit[i] = 1;
	check_(arr[i]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr.resize(N + 1);
	visit.resize(N + 1, 0);
	for (int i = 1; i < N + 1; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < N + 1; i++)
	{
		if (visit[i])continue;
		vector<bool> check(N + 1, 0);
		if (DFS(check, i, i))
		{
			check_(i);
		}
	}
	sort(res.begin(), res.end());
	cout << sum << endl;
	for (int i = 0; i < res.size(); i++)
	{
		printf("%d\n", res[i]);
	}
	return 0;
}