/*
Q)	���� ���� ���

S)	1. 1:�� / 0:�ٴ�
	2. 0,0 �Է½� ����

A)	1. H,W�Է�
	2. bfs ��� ���ư� �� �ִ��� üũ
	3. �� bfs���� visited[][] memset -> cstring
 
// Testcase error
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
0 0

*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define SIZE 55

int H{}, W{};
int map[SIZE][SIZE]{};
bool visited[SIZE][SIZE]{};

// �´밢�� -> �ð����
int dy[] = { -1,-1,-1,0,1,1,1,0 };
int dx[] = { -1,0,1,1,1,0,-1,-1 };

bool input_data() {
	cin >> W >> H;
	if (H == 0 && W == 0)	return true;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	return false;
}

void init() {
	memset(visited, false, sizeof(visited));
	memset(map, 0, sizeof(map));
}

void bfs(int my, int mx) {
	queue <pair<int, int>> q{};

	q.push(make_pair(my, mx));
	visited[my][mx] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			
			if (ny < 0 || nx < 0 || ny >= H || nx >= W)	continue;
			if (!visited[ny][nx] && map[ny][nx]) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
}

void solution() {
	int nWnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (!visited[i][j] && map[i][j]) {
				bfs(i,j);
				nWnt++;
			}
		}
	}

	cout << nWnt << endl;
}


int main() {
	while (true) {
		init();
		if (input_data())	break;
		solution();
	}
	return 0;
}
