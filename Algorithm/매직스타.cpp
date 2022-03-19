/*
# 3967 ���� ��Ÿ

Q)  ���� �� ä���� ���� ��Ÿ �����

S)  1. �� 6���� ������ ���� �����ؾ� ��
    2. 2���� ��ġ�� ���ڵ��� �� 6��
    3. ���� �� 12�� A~L����

A)  1. �ʿ� �ִ� ���� ���
    2. check[] -> ��ȣ �ߺ� ��� ����
    3. temp[][] -> ��ο� ��ġ�� ���� ���
    4. DFS ���� -> map�� idx �̸� ���, �˻� 5,8,11,12
    5. 

*/
#include <iostream>
#include <string>
using namespace std;
char map[5][9]{};
bool check[12]{};
bool finish{};
int num[12]{};

int idxMap[6][4] = {
	{0,2,5,7},
	{0,3,6,10},
	{7,8,9,10},
	{1,2,3,4},
	{1,5,8,11},
	{4,6,9,11}
};

void dfs(int idx) {
	if (finish) return;

	if (idx == 12) {
		int t = 0;
		for (int j = 0; j < 4; j++) {
			t += num[idxMap[4][j]];
		}
		if (t != 22)	return;
		
		t = 0;
		for (int j = 0; j < 4; j++) {
			t += num[idxMap[5][j]];
		}
		if (t != 22)	return;

		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (map[i][j] != '.') {
					char c = num[cnt++] + 'A';
					cout << c;
				}
				else
					cout << map[i][j];
			}
			cout << endl;
		}
		finish = true;
		return;
	}

	if (idx == 5) {
		int t = 0;
		for (int j = 0; j < 4; j++)
			t += num[idxMap[3][j]];
		if (t != 22) return;
	}
	else if (idx == 8) {
		int t = 0;
		for (int j = 0; j < 4; j++)
			t += num[idxMap[0][j]];
		if (t != 22) return;
	}
	else if (idx == 11) {
		int t = 0;
		for (int j = 0; j < 4; j++)
			t += num[idxMap[2][j]];
		if (t != 22) return;
		t = 0;
		for (int j = 0; j < 4; j++)
			t += num[idxMap[1][j]];
		if (t != 22) return;
	}

	//�̹� ��ȣ�� �ִ� ���
	if (num[idx] != -1) {
		dfs(idx + 1);
	}
	else {
		for (int i = 0; i < 12; i++) {
			if (check[i]) continue;
			check[i] = true;
			num[idx] = i;
			dfs(idx + 1);
			num[idx] = -1;
			check[i] = false;
		}
	}
}

void init() {
	for (int i = 0; i < 12; i++) {
		num[i] = -1;
	}
}

void input_data() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			char c = map[i][j];
			if (c != '.') {
				if (c == 'x') cnt++;
				else {
					check[c - 'A'] = true;
					num[cnt++] = c - 'A';
				}
			}
		}
	}
}

void solution() {
	dfs(0);
}

int main() {
	init();
	input_data();
	solution();
	return 0;
}
