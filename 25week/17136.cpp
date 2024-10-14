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

int paper[5] = {5,5,5,5,5};
int total = 26;
vector<vector<int>> place(10, vector<int>(10));

bool Check()
{
	for ( int i = 0; i < 10; i++ )
	{
		for ( int j = 0; j < 10; j++ )
		{
			if ( place[i][j] == 1 )return false;
		}
	}
	return true;
}

bool CanFill(int width, int y, int x)
{
	if ( y + width >= 10 || x + width >= 10 )return false;
	for ( int i = y; i <= y + width; i++ )
	{
		for ( int j = x; j <= x + width; j++ )
		{
			if ( place[i][j] == 0 )return false;
		}
	}
	return true;
}

void Fill(int width, int y, int x)
{
	for ( int i = y; i <= y + width; i++ )
	{
		for ( int j = x; j <= x + width; j++ )
		{
			place[i][j] = 0;
		}
	}
}

void UnFill(int width, int y, int x)
{
	for ( int i = y; i <= y + width; i++ )
	{
		for ( int j = x; j <= x + width; j++ )
		{
			place[i][j] = 1;
		}
	}
}
int SumPaper()
{
	int sum = 0;
	for ( int i = 0; i < 5; i++ )
	{
		sum += 5 - paper[i];
	}
	return sum;
}

pair<int, int> ReturnPos()
{
	for ( int i = 0; i < 10; i++ )
	{
		for ( int j = 0; j < 10; j++ )
		{
			if ( place[i][j] == 1 )return { i,j };
		}
	}
}
void Back()
{
	if ( Check() )
	{
		total = min(total, SumPaper());
		return;
	}
	pair<int, int> a = ReturnPos();
	int curY = a.first;
	int curX = a.second;
	int width;
	for (width = 0; width < 5; width++ )
	{
		if ( paper[width] == 0 )continue;
		if ( CanFill(width, curY, curX) )
		{
			Fill(width, curY, curX);
			paper[width]--;
			Back();
			paper[width]++;
			UnFill(width, curY, curX);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	for ( int i = 0; i < 10; i++ )
	{
		for ( int j = 0; j < 10; j++ )
		{
			cin >> place[i][j];
		}
	}
	
	Back();
	if ( total == 26 )
	{
		cout << -1 << endl;
		return 0;
	}
	cout << total << endl;
	return 0;
}