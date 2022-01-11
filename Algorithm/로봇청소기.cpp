#include <iostream>
using namespace std;

#define SIZE 52

int n{}, m{};
int map[SIZE][SIZE]{};
int ry{}, rx{}, rd{};
int cnt{};

// �ϵ�����(����)
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void input_data() {
	cin >> n >> m;
	cin >> ry >> rx >> rd;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void dfs(int y, int x, int dir) {
	//��
	if (map[y][x] == 1)	return;

	//��ĭ
	if (map[y][x] == 0) {
		//û���� ���� -> 5�� �ٲ�
		map[y][x] = 2;
		cnt++;
	}

	// 4 ���� �˻�
	for (int k = 0; k < 4; k++) {
		int ndir = dir - 1 < 0 ? 3 : dir - 1;
		int ny = y + dy[ndir];
		int nx = x + dx[ndir];

		// ���� ĭ���� �Ѿ ��� ������ �˻� X
		if (map[ny][nx] == 0) {
			dfs(ny, nx, ndir);
			return;
		}
		else {
			// û�Ҹ� �߰ų� ���̸� ���⸸ �ٲ�
			dir = ndir;
		}
	}

	// �� ���� ��� û���߰ų� ���̸� ������ ������ä�� ����
	int ndir = (dir + 2) % 4;
	dfs(y + dy[ndir], x + dx[ndir], dir);
}

void solution() {

	//logic
	dfs(ry, rx, rd);

	//result
	cout << cnt << endl;
}

int main() {
	//init
	cnt = 0;

	//input
	input_data();
	
	//solve
	solution();

	return 0;
}