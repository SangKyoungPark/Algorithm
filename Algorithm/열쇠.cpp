/*
Q)	����̰� ��ĥ �� �ִ� ������ �ִ� ������ ���ض�

S)	1. �����¿�θ� ������
	2. . ����� / * �� / $ ����(���ľ���)
	3. ���ĺ� �빮�� - ��
	4. �ҹ��� - ����
	5. �����ڸ����� ���� �ƴ� ������ �� �� �ִ�.

A)	1. tc�Է�
	2. H , W -> �ʻ�����
	3. ����̰� ������ �ִ� ���� �Է�
	4. ���� �ڸ� ���� �ƴѰ� queue ���
	5. ����̰� ������ �ִ� ���� Ű hsahmap -> ť�� ��ġ�ϴ°� �ִٸ� ��� Ž��(BFS)

*/

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
#define SIZE 110

int H{}, W{};
int nRes;
char map[SIZE][SIZE]{};
bool visited[SIZE][SIZE]{};
bool key[26]{};
string input_key;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

vector <pair<int, int>> door{};

void bfs() {
    queue <pair<int,int>> Q;
    Q.push(make_pair(0, 0));
    visited[0][0] = true;

    while (!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > H+1 || nx < 0 || nx > W+1) continue;
            if (map[ny][nx] == '*') continue;
            if (visited[ny][nx]) continue;

            // ���� ���� ���
            if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z') {
                int idx = map[ny][nx] - 'A';
                // ���踦 ������ ���
                if (key[idx]) {
                    Q.push(make_pair(ny, nx));
                    visited[ny][nx] = true;
                }
                // ���谡 ���� ���
                else {
                    door.push_back(make_pair(ny, nx));
                }
            }
            // ���踦 ���� ���
            else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z') {
                int idx = map[ny][nx] - 'a';
                key[idx] = true;
                size_t size = door.size();
                for (int i = 0; i < size; i++) {
                    int py = door[i].first;
                    int px = door[i].second;

                    if (py == -1 && px == -1) continue;

                    if (idx == map[py][px] - 'A') {
                        Q.push(make_pair(py, px));
                        visited[py][px] = true;

                        door[i].first = -1;
                        door[i].second = -1;
                    }
                }

                Q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
            }
            // ������ ���� ���
            else if (map[ny][nx] == '$') {
                nRes++;
                Q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
            }
            // ������ ���
            else {
                Q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }
    door.clear();
}

void input_data() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> map[i][j];
		}
	}
    cin >> input_key;
}

void solution() {
    if (input_key != "0") {
        int size = input_key.size();
        for (int i = 0; i < size; i++) {
            key[input_key[i] - 'a'] = true;
        }
    }
    nRes = 0;

    bfs();

    //result
    cout << nRes << endl;
}

void init() {
    memset(map, NULL, sizeof(map));
    memset(visited, false, sizeof(visited));
    memset(key, false, sizeof(key));
}

int main() {
	int tc{};
	cin >> tc;
	for (int t = 0; t < tc; t++) {
        init();
		input_data();
		solution();
	}
}