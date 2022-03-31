/*
Q)	����̰� ��� ������ �����ϱ� ���� Ÿ���ϴ� ����� �ּ� ����

S)	1. ������ �� N / ����� ���� M
	2. M�� �� a,b (a-b)�պ��ϴ� �����

A)	1. N M �Է�
	2. a,b (m�� ����)
	3. airplane[N] / �� �迭�� �°� idx -> ����� �� ã��
	4. MST �˰���
*/

#include <iostream>
using namespace std;

int N{}, M{};

void input_data() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a{}, b{};
		cin >> a >> b;
	}
}

void solution() {
	// ��� ��� ���� + ����ġ X
	// -> MST -> Node-1 = O(1)
	cout << N - 1 << endl;
}


int main() {
	int tc{};
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		input_data();
		solution();
	}
	return 0;
}