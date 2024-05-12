#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
�̺�Ž������ ������ ������ ã�ư��� ���



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
		mid = (left + right) / 2;			//������ ����
		if ( mid == 0 ) mid = 1;			//0 1 ���� ���̽� ó��
		//auto start = wifi.begin();
		int start = wifi[0];				//wifi[0]���� �����Ͽ� ������ ����ã�� ���� 
		int cnt = 1;						//wifi[0]�� ������ cnt
		int _mid = wifi[0] + mid;			//���� ������ ���� ��ġ
		for ( int i = 1; i < N; i++ ) {	
			if ( wifi[i] >= _mid ) {		//���� ������ ��ġ�� �´� �� �߰�
				cnt++;						
				_mid = wifi[i] + mid;		//���� �缳��
			}
		}
		/*
		* 
		* lower_bound�� ����غ������� �����߻�..
		* 
		while ( 1 ) {
			start = lower_bound(start, wifi.end(), _mid);
			if ( start == wifi.end() )break;
			_mid = *start + mid;
			cnt++;

		}
		*/
		if ( cnt >= C ) {					//���� ��ǥ�޼�
			left = mid + 1;					//������ ������ ã������ left�� �缳�� ->���� �þ
			res = mid;						//���� ����
		}
		else {
			right = mid - 1;				//������ ��ǥ���� �����Ƿ� ������ ���������� right�� �缳��
		}

	}
	cout << res << endl;
	return 0;
}