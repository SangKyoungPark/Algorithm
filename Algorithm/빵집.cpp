/*
Q)	�������� ������ �����ϴ� ������������ �ִ� ���� ���ض�

S)	1. ù��° �� : ������ ������
	2. ������ �� : �������� ����
	3. ù��°���� ������ ���� �����ϴ� �������� ��ġ�Ϸ� ��
	(* ��, �ǹ��� �����ϸ� ������ ��ġ X)
	4. ������, ������ �� �밢��, ������ �Ʒ� �밢�� ���� ����

TC)
01x.443210
..23.x....

0xx..
.1x10
..2..
...x.
...x.

A)	1. R,C �Է�
	2. BFS ���� ���� ���� ������ �� ���
	3. visited check�ϸ� ���� -> ������ ���� �ִٸ� ���ϱ� 1 �ϰ� ����
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define SIZE 10010

int R{}, C{};
int map[SIZE][SIZE]{};
bool visited[SIZE][SIZE]{};


queue <pair<int, int>> Q{};

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
				map[i][j] = -1;
			}
		}
	}
}

void bfs() {
	int nRes{};

	//init
	for (int i = 0; i < R; i++) {
		Q.push(make_pair(i, 0));
	}
	nRes = 0;
	// ���� / �밢�� / �밢 �Ʒ� / 
	int dy[3] = { 0, -1, 1};
	int dx[3] = { 1, 1, 1 };

	while (!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for (int k = 0; k < 3; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C)	continue;
			if (!visited[ny][nx] && map[ny][nx] != -1) {
				Q.push(make_pair(ny, nx));
				map[ny][nx] = map[y][x] + 1;
				visited[ny][nx] = true;
				if (nx == C - 1)	return;
			}
		}
	}
}

void solution() {
	//init
	memset(visited, false, sizeof(visited));
	
	//logic
	bfs();

	//result
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {
	input_data();

	solution();

	return 0;
}