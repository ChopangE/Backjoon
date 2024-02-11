#include<iostream>
#include<vector>


using namespace std;


int main() {
	int N;
	cin >> N;
	vector<bool> check(N + 1, 0);
	vector<int> ane;
	check[0] = 1;
	check[1] = 1;
	for ( int i = 2; i * i < N + 1; i++ ) {
		if ( check[i] == 0 ) {
			for ( int j = i * 2; j < N + 1; j += i ) {
				check[j] = 1;
			}
		}
	}
	for ( int i = 2; i < N + 1; i++ ) {
		if ( check[i] == 0 )ane.push_back(i);
	}
	int last = 0;
	int first = 0;
	int sum = 0;
	int size = ane.size();
	int count = 0;
	while ( 1 ) {
		if ( sum >= N && first < size ) {
			sum -= ane[first++];
		}
		if ( sum < N  ) {
			if ( last < size )sum += ane[last++];
			else break;
		}
		if ( first == size && last == size )break;

		if ( sum == N ) {
			count++;
		}
	}

	cout << count << endl;


	return 0;
}