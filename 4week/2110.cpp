#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
이분탐색으로 최적의 간격을 찾아가는 방법



*/
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N, C;
	cin >> N >> C;
	vector<int> wifi(N);

	for ( int i = 0; i < N; i++ ) {
		cin >> wifi[i];
	}
	sort(wifi.begin(), wifi.end());
	int left = 0;
	int right = wifi[N - 1] - wifi[0];
	int mid = 0;
	int res = 0;
	while ( left <= right ) {
		mid = (left + right) / 2;			//공유기 간격
		if ( mid == 0 ) mid = 1;			//0 1 예외 케이스 처리
		//auto start = wifi.begin();
		int start = wifi[0];				//wifi[0]부터 시작하여 최적의 간격찾는 과정 
		int cnt = 1;						//wifi[0]을 포함한 cnt
		int _mid = wifi[0] + mid;			//다음 공유기 예상 위치
		for ( int i = 1; i < N; i++ ) {	
			if ( wifi[i] >= _mid ) {		//다음 공유기 위치에 맞는 집 발견
				cnt++;						
				_mid = wifi[i] + mid;		//간격 재설정
			}
		}
		/*
		* 
		* lower_bound를 사용해보았지만 오류발생..
		* 
		while ( 1 ) {
			start = lower_bound(start, wifi.end(), _mid);
			if ( start == wifi.end() )break;
			_mid = *start + mid;
			cnt++;

		}
		*/
		if ( cnt >= C ) {					//예상 목표달성
			left = mid + 1;					//최적의 간격을 찾기위해 left를 재설정 ->간격 늘어남
			res = mid;						//간격 저장
		}
		else {
			right = mid - 1;				//개수가 목표보다 적으므로 간격을 좁히기위해 right를 재설정
		}

	}
	cout << res << endl;
	return 0;
}