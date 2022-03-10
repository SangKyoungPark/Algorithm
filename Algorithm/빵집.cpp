/*
Q)	�������� ������ �����ϴ� ������������ �ִ� ���� ���ض�

S)	1. ù��° �� : ������ ������
	2. ������ �� : �������� ����
	3. ù��°���� ������ ���� �����ϴ� �������� ��ġ�Ϸ� ��
	(* ��, �ǹ��� �����ϸ� ������ ��ġ X)
	4. ������, ������ �� �밢��, ������ �Ʒ� �밢�� ���� ����

A)	1. ������ ��/���� /������ �Ʒ� ������ Ž�� ( ��Ž�� X)
	2. dfs ����Ͽ� �ش� �Ÿ����� �� �� �ִ� ������ ���Ǵ� �ϵ��� ������ ��
	3. ������ �����ϰ� �Ǹ� ( c == C-1 ) count++;
*/

#include <iostream>
using namespace std;
#define SIZE 10010

int R{}, C{};
int nCnt;
int map[SIZE][510]{};

int dr[] = { -1,0,1 };
int dc[] = { 1,1,1 };

void input_data() {
	char temp;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> temp;
			if (temp == '.') {
				map[i][j] = 0;
			}
			else if (temp == 'x') {
				map[i][j] = 1;
			}
		}
	}
}

bool dfs(int r, int c) {
	if (c == C - 1) {
		nCnt++;
		return true;
	}

	map[r][c] = 1;
	for (int k = 0; k < 3; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];
		if (nr < 0 || nc < 0 || nr >= R || nc >= C)	continue;
		if (!map[nr][nc]) {
			if (dfs(nr, nc)) {
				return true;
			}
		}
	}
	return false;
}

void solution() {
	//logic
	for (int i = 0; i < R; i++) {
		dfs(i, 0);
	}

	//result
	cout << nCnt;
}

int main() {
	input_data();

	solution();

	return 0;
}