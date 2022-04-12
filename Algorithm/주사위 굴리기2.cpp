#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, K;
bool visit[21][21];
int map[21][21];
int dice[] = { 1,6,4,3,5,2 };
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

int y = 1, x = 1;
int dir = 0;

void update_dice() {
	int up, down, left, right, front, back;
	up = dice[0];
	down = dice[1];
	left = dice[2];
	right = dice[3];
	front = dice[4];
	back = dice[5];
	// �������� ����
	if (dir == 0) {
		dice[0] = left;
		dice[1] = right;
		dice[2] = down;
		dice[3] = up;
	}
	//�������� ����
	else if (dir == 1) {
		dice[0] = back;
		dice[1] = front;
		dice[4] = up;
		dice[5] = down;
	}
	//�������� ����
	else if (dir == 2) {
		dice[0] = right;
		dice[1] = left;
		dice[2] = up;
		dice[3] = down;
	}
	//�������� ����
	else {
		dice[0] = front;
		dice[1] = back;
		dice[4] = down;
		dice[5] = up;
	}

}

void update_dir() {
	//�ð� ���� 90�� ȸ��
	if (dice[1] > map[y][x]) {
		dir = (dir + 1) % 4;
	}
	//�ݽð� ���� 90�� ȸ��
	else if (dice[1] < map[y][x]) {
		dir = (4 + dir - 1) % 4;
	}
}

// �ֻ��� �̵�
void move_dice() {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	//�̵� �Ұ� -> �ݴ� �������� ���� ����
	if (ny<1 || nx<1 || ny>N || nx>M) {
		dir = (dir + 2) % 4;
		ny = y + dy[dir];
		nx = x + dx[dir];
	}
	// �ֻ����� ���� �̵� �ϹǷ� �ֻ����� �����¿��� ���� ����
	update_dice();
	y = ny; x = nx;
}

//bfs ���� ���� ���� ĭ�� �� ���ϱ�
int search_continuous() {
	int value = map[y][x];
	int cnt = 1;

	memset(visit, false, sizeof(visit));
	visit[y][x] = true;
	queue<pair<int, int>>q;
	q.push(make_pair(y, x));

	int ny, nx;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			ny = y + dy[d];
			nx = x + dx[d];
			if (ny<1 || nx<1 || ny>N || nx>M)continue;
			if (visit[ny][nx])continue;
			visit[ny][nx] = true;
			if (map[ny][nx] == value) {
				q.push(make_pair(ny, nx));
				cnt++;
			}
		}
	}
	return cnt;
}


int main() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	int score = 0;
	for (int i = 0; i < K; i++) {
		move_dice();
		//���� �߰�
		score += map[y][x] * search_continuous();
		update_dir();
	}
	cout << score;
	return 0;
}