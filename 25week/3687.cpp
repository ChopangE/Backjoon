#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<string>

using namespace std;

typedef pair<int, int> ii;

int T;
int n;

vector<long long> min_dp(101);
vector<string> max_dp(101);

int num[8] = { -1,-1,1,7,4,2,0,8 };
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	min_dp[2] = 1;
	max_dp[2] = "1";
	min_dp[3] = 7;
	max_dp[3] = "7";
	min_dp[4] = 4;
	max_dp[4] = "11";
	min_dp[5] = 2;
	max_dp[5] = "71";
	min_dp[6] = 6;
	max_dp[6] = "111";
	min_dp[7] = 8;
	max_dp[7] = "711";
	min_dp[8] = 10;
	max_dp[8] = "1111";
	for ( int i = 9; i < 101; i++ )
	{
		max_dp[i] = max_dp[i - 2] + "1";
		int j;
		min_dp[i] = min_dp[i - 7] * 10 + 8;
		for ( j = 6; j >= 2; j-- )
		{
			min_dp[i] = min(min_dp[i], min_dp[i - j] * 10 + num[j]);
		}
		
		/*int tmp = stoi(min_dp[i - 7] + "8");
		if ( tmp > stoi(min_dp[i - 6] + "0") )
		{
			tmp = stoi(min_dp[i - 6] + "0")	;
		}*/
		//min_dp[i] = to_string(tmp);
	}
	for ( int t = 0; t < T; t++ )
	{
		cin >> n;
		cout << min_dp[n] << " " << max_dp[n] << endl;
	}
	return 0;
}