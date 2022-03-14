/*
Q)	��ĥ�� ������ �������� ���� �� �ִ��� ���

S)	1. R x C ���
	2. �� ������ ������ ��� ���� ������ ��´�. (�밢�� ��� X)
	3 �� . / ���� X / ���� L

A)	1. ���� ��ġ �ľ�
	2. ���� �� �ִ��� ������ �Ǵ�
	3. (���� ������ ��� ť�� �ְ� bfs) ���� ���̱� -> �����¿� ���� ������ ť���� ����

*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define SIZE 1505

int R{}, C{};
int nDay{};
char map[SIZE][SIZE]{};
bool visited[SIZE][SIZE]{};

vector <pair<int, int>> ice{};
vector <pair<int, int>> swan{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void input_data() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			//init
			if (map[i][j] == 'X') {
				ice.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 'L') {
				swan.push_back(make_pair(i, j));
			}
		}
	}
}

void dfs(int my, int mx) {
	if (my == swan[1].first && mx == swan[1].second) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = my + dy[i];
		int nx = mx + dx[i];

		if (ny < 0 || nx < 0 || ny >= R || nx >= C)	continue;
		if (!visited[ny][nx] && map[ny][nx] == '.') {
			visited[ny][nx] = true;
			dfs(ny, nx);
			//visited[ny][nx] = false;
		}
	}
}

bool isContect() {
	memset(visited, false, sizeof(visited));
	visited[swan.front().first][swan.front().second] = true;
	dfs(swan.front().first, swan.front().second);
	if (visited[swan[1].first][swan[1].second]) {
		return true;
	}
	else {
		return false;
	}
}

void melting() {
	// ��ü�� �� 1���� �� �� �ֵ��� �����ؾ���
	// �߰��� �����ϸ� ���̿� ���� �ε����� ��迭�Ǵ� ���� �߻�
	int iceSize = ice.size();

	for (int i = 0; i < iceSize; i++) {
		int y = ice[i].first;
		int x = ice[i].second;

		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C)	continue;
			if (map[ny][nx] == '.') {
				map[y][x] = '.';
				ice.erase(ice.begin() + i);
			}
		}
	}
}

void solution() {
	if (isContect()) {
		cout << nDay << endl;
	}
	else {
		melting();
		nDay++;
	}
}

void init() {
	nDay = 0;
}

int main() {
	//init
	init();

	//input
	input_data();
	//solution
	solution();
	return 0;
}