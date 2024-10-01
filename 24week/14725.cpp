#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;

int N;

struct Node
{
	string key;
	vector<Node> childs;
};

bool cmp(Node& a, Node& b)
{
	return a.key < b.key;
}

void Print(vector<Node> &cur, string str)
{
	sort(cur.begin(), cur.end(), cmp);
	for (Node& next : cur)
	{
		string printStr = str + next.key;
		cout << printStr << endl;
		//printf("%s", printStr);
		Print(next.childs, str + "--");
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<Node> nodes;
	for (int i = 0; i < N; i++)
	{
		int t;
		string s;
		cin >> t;
		vector<Node>* target = &nodes;
		for (int j = 0; j < t; j++)
		{
			cin >> s;
			bool isCheck = false;
			for (int k = 0; k < target->size(); k++)
			{
				if ((*target)[k].key == s)
				{
					isCheck = true;
					target = &(*target)[k].childs;
					break;
				}
			}
			if (!isCheck)
			{
				Node a;
				a.key = s;
				target->push_back(a);
				target = &(target->back().childs);
			}
		}
	}
	Print(nodes, "");
	return 0;
}