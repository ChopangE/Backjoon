#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>
#include<set>
#include<cmath>

using namespace std;

typedef pair<int, int> ii;

int N, K, S;
vector<ii> arr;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> S;

	arr.resize(N);

	for ( int i = 0; i < N; i++ )
	{
		int a, b;
		cin >> a >> b;
		arr[i].first = a;
		arr[i].second = b;
	}

	sort(arr.begin(), arr.end());
	int total = 0;
	int left = 0;
	int right = N - 1;
	while ( left <= right )
	{
		if ( arr[left].first < S )
		{
			int tmp = 0;
			int first_left = left;
			while ( true )
			{
				if ( left >= N || arr[left].first > S )break;

				if ( arr[left].second <= K - tmp )
				{
					tmp += arr[left].second;
					left++;
				}
				else
				{
					arr[left].second -= K - tmp;
					break;
				}
			}
			total += 2 * abs(S - arr[first_left].first);
		}
		else
		{
			int tmp = 0;
			int first_right = right;
			while ( true )
			{
				if (right < 0 ||  arr[right].first < S )break;

				if ( arr[right].second <= K - tmp )
				{
					tmp += arr[right].second;
					right--;
				}
				else
				{
					arr[right].second -= K - tmp;
					break;
				}
			}
			total += 2 * abs(S - arr[first_right].first);
		}
	}
	cout << total << endl;
	return 0;
}