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

vector<int> arr;
vector<long long> index;
int N, M, K;

long long TreeInit(int left, int right, int idx)
{
	if ( left == right )
	{
		index[idx] = arr[left];
		return arr[left];
	}
	int mid = (left + right) / 2;
	long long t = (TreeInit(left, mid, 2 * idx) % 1000000007) * (TreeInit(mid + 1, right, 2 * idx + 1) % 1000000007) % 1000000007;
	return index[idx] = t;
}

void UpdateTree(int left, int right, int idx, int &original, int &new_, int &t_idx)
{
	if ( right < t_idx || left > t_idx ) return;
	if ( left == right )
	{
		index[idx] = new_;
		return;
	}
	int mid = (left + right) / 2;
	UpdateTree(left, mid, 2 * idx, original, new_, t_idx);
	UpdateTree(mid + 1, right, 2 * idx + 1, original, new_, t_idx);
	index[idx] = (index[2 * idx] % 1000000007) * (index[2 * idx + 1] % 1000000007);
}

long long printTree(int left, int right, int first, int last, int idx)
{
	if ( last < left || right < first )
	{
		return 1;
	}
	if ( first <= left && right <= last ) return index[idx];
	int mid = (left + right) / 2;
	long long t = ((printTree(left, mid, first, last, 2 * idx) % 1000000007) * (printTree(mid + 1, right, first, last, 2 * idx + 1) % 1000000007)) % 1000000007;
	return t;
}



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	arr.resize(N + 1);
	index.resize(4 * N);
	for ( int i = 1; i <= N; i++ )
	{
		cin >> arr[i];
	}

	TreeInit(1, N, 1);
	for ( int i = 0; i < M + K; i++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		if ( a == 1 )		//바꾸기
		{
			UpdateTree(1, N, 1, arr[b], c, b);
			arr[b] = c;
		}
		else                //출력
		{
			cout << printTree(1, N, b, c, 1) << endl;
		}
		
	}


	return 0;
}