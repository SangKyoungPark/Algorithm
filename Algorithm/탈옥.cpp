/*
Q)	2���� �˼��� Ż����Ű�� ���� ����� �ϴ� ���� ���� ���ض�

S)	1. H / W <= 100
	2. ����� . | �� * | �� # | �˼� $

A)	1. tc -> map �Է�
	2. �ۿ��� ������ ��η� �Ǵ�
*/
#include <iostream>
#include <vector>
using namespace std;

#define SIZE 110

int R{}, C{};
char map[SIZE][SIZE]{};
bool visited[SIZE][SIZE]{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

vector <pair<int, int>> door{};

void input_data() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				door.push_back(make_pair(i, j));
				map[i][j] = '.';
			}
		}
	}
}

void solution() {
	//init
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
		}
	}
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