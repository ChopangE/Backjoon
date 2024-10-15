#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<string>
#include<limits>

using namespace std;

int N, K;
string str;

stack<char> sta;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	cin >> str;

	for ( int i = 0; i < N; i++ )
	{
		if ( sta.empty() || sta.top() >= str[i] )
		{
			sta.push(str[i]);
		}
		else if ( sta.top() < str[i] )
		{
			while ( !sta.empty() && K > 0 && sta.top() < str[i] )
			{
				sta.pop();
				K--;
			}
			sta.push(str[i]);
		}
	}

	while ( K > 0 )
	{
		sta.pop();
		K--;
	}

	stack<char> res;
	while ( !sta.empty() )
	{
		res.push(sta.top());
		sta.pop();
	}
	while ( !res.empty() )
	{
		printf("%c", res.top());
		res.pop();
	}

	return 0;
}