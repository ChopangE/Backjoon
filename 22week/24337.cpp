#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>
#include<set>

using namespace std;

int N,a,b;
vector<int> res;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> a >> b;
	if ( a + b > N + 1 )
	{
		cout << -1 << endl;
		return 0;
	}
	res.resize(N);
	if ( a == 1 )
	{
		
		res[0] = b--;
		int b_ = b;
		for ( int i = N - b; i < N; i++ )
		{
			if ( b == 0 )b = 1;
			res[i] = b--;
		}
		for ( int i = 1; i < N - b_; i++ )
		{
			res[i] = 1;
		}
	}
	else
	{
		if ( a >= b )
		{
			int a_ = a;
			int b_ = b;
			res[N - b] = a_;
			for ( int i = N - b + 1; i < N; i++ )
			{
				res[i] = --b_;
			}
			for ( int i = N - b - 1; i >= 0; i-- )
			{
				--a_;
				if ( a_ == 0 ) a_ = 1;
				res[i] = a_;
			}
		}
		else
		{
			int a_ = a;
			int b_ = b;
			res[N - b] = b_;
			for ( int i = N - b + 1; i < N; i++ )
			{
				res[i] = --b_;
			}
			for ( int i = N - b - 1; i >= 0; i-- )
			{
				--a_;
				if ( a_ == 0 ) a_ = 1;
				res[i] = a_;
			}
		}
	}

	for ( int i = 0; i < N; i++ )
	{
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}