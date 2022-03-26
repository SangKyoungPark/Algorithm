/*
Q)	������� �����ϴ���?

S)	1. ����� 1ĭ / ������ Nĭ
	2. ���û��� - ���� ��ŭ �̵��ؾ� �ϴ���
	3. Nĭ ���� �� Nĭ �Ѿ�� ����
	4. �ֻ��� ����ŭ �̵� -> ���ÿ� ���� -> ����(���û��� ���� ����)

A)	1. N M �Է�
	2. N �� for �� -> ���Է�
	3. M �� for �� -> �ֻ��� �Է�
	4. S-4���� ������. 
*/

#include <iostream>
using namespace std;
#define SIZE 1010

int n{}, m{};
int map[SIZE]{};
int dice[SIZE]{};

int nIdx{};

void input_data() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> dice[i];
	}
}

void solution() {
	//init
	nIdx = 1;

	for (int i = 1; i <= m; i++) {
		// ����ŭ �̵�
		nIdx += dice[i];
		if (nIdx >= n) {
			cout << i << endl;
			return;
		}
		// ���ÿ� ���� -> ����
		nIdx += map[nIdx];
		if (nIdx <= 1)	nIdx = 1;
		if (nIdx >= n) {
			cout << i << endl;
			return;
		}
	}
}

int main() {
	input_data();
	solution();
	return 0;
}