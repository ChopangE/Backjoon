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

int N;
vector<char> oper;
vector<int> num;
vector<bool> check;
int total = numeric_limits<int>::min();

void Cal()
{
	vector<int> res;
	for ( int i = 0; i < N / 2 + 1; i++ )
	{
		if ( i == N / 2 )
		{
			res.push_back(num[i]);
			break;
		}
		
		if ( check[i] == true )
		{
			int a;
			if ( oper[i] == '-' )
			{
				a = num[i] - num[i + 1];
			}
			else if ( oper[i] == '+' )
			{
				a = num[i] + num[i + 1];
			}
			else if ( oper[i] == '*' )
			{
				a = num[i] * num[i + 1];
			}
			res.push_back(a);
			i++;
		}
		else
		{
			res.push_back(num[i]);
		}
	}
	int idx = 0;
	int sum = res[idx++];
	for ( int i = 0; i < N / 2; i++ )
	{
		if ( check[i] == false )
		{
			if ( oper[i] == '-' )
			{
				sum = sum - res[idx++];
			}
			else if ( oper[i] == '+' )
			{
				sum = sum + res[idx++];
			}
			else if ( oper[i] == '*' )
			{
				sum = sum * res[idx++];
			}
		}
	}
	total = max(total, sum);
}

void Back(int i)
{
	if ( i == N / 2 )
	{
		Cal();
		return;
	}
	if ( i != 0 )
	{
		if ( check[i - 1] == true )
		{
			Back(i + 1);
			return;
		}
	}
	for ( int j = 0; j < 2; j++ )
	{
		check[i] = j == 0;
		Back(i + 1);
		check[i] = false;
	}

}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	oper.resize(N / 2);
	check.resize(N / 2, false);
	num.resize(N / 2 + 1);

	for ( int i = 0; i < N; i++ )
	{
		if ( i % 2 == 0 )
		{
			cin >> num[i / 2];
		}
		else
		{
			cin >> oper[i / 2];
		}
	}
	Back(0);
	cout << total << endl;
	return 0;
}