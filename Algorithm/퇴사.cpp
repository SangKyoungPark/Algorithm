#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 20

int n{};
int day[SIZE]{};
int cost[SIZE]{};
int dp[SIZE]{};

void input_data() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> day[i] >> cost[i];
	}
}

/*
 d[n]�� n+1�� ���� �� �ִ� �ִ� �ݾ��� �ǹ�
 �Ʒ��� ���ÿ��� 1�Ͽ� ���� �ϸ� 3�ϵ��� ���� �ϱ� ������ 4�Ͽ� �ݾ��� ����
   1  2  3  4
 t 3  5  1  1
 p 10 20 10 20
 d 0  0  0  10
*/
void solution() {
	int nRes{};

	//logic
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] = max(dp[i], dp[j]);
			if (j + day[j] == i) {
				dp[i] = max(dp[i], dp[j] + cost[j]);
			}
		}
		nRes = max(nRes, dp[i]);
	}
	//result
	cout << nRes << endl;
}

int main() {
	//input
	input_data();

	//solve
	solution();

	return 0;
}