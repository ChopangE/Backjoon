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
typedef pair<int, ii> iii;

int N;
vector<iii> arr;
vector<int> s;


int Find(int x)
{
	if ( s[x] == -1 )return x;
	return s[x] = Find(s[x]);
}

void Union(int a, int b)
{
	int s_a = Find(a);
	int s_b = Find(b);
	if ( s_a == s_b )return;
	if ( s_a < s_b )s[s_b] = s_a;
	else s[s_a] = s_b;
}

bool cmp(iii& a, iii& b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	s.resize(N + 1, -1);
	for ( int i = 1; i < N + 1; i++ )
	{
		int t;
		cin >> t;
		arr.push_back(iii{ t,{0,i} });
	}
	for ( int i = 1; i < N + 1 ; i++ )
	{
		for ( int j = 1; j < N + 1 ; j++ )
		{
			int t;
			cin >> t;
			if ( i < j )arr.push_back(iii{ t,{i,j} });
		}
		
	}
	
	sort(arr.begin(), arr.end(), cmp);

	
	int total = 0;
	
	for ( int i = 0; i < arr.size(); i++ )
	{
		iii &a = arr[i];
		
		if ( Find(a.second.first) != Find(a.second.second) )
		{
			total += a.first;
			Union(a.second.first, a.second.second);
		}
		
	}
	cout << total << endl;
	return 0;
}