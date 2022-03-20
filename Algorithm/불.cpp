/*
Q)	�����̰� �ҿ� Ÿ������ Ż���� �� �ִ� �� ����
	+ �󸶳� ���� Ż���� �� ������?

S)	1. ��# / ����. / �ʱ���ġJ/  �� F
	2. ����,�� -> �����¿�θ� ������
	4. ���� 4���� ��η� Ȯ���
	5. �����̰� �̷� �����ڸ��� ���ϸ� Ż��

A)	1. �� -> queue�� �� ���
	2. �� �ð� Ž�� -> bfs
	3. �����̰� Ż�� -> bfs 
*/
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#define SIZE 1005

int R{}, C{};
string map[SIZE]{};
bool visited[SIZE][SIZE]{};

pair<int, int> start{};
vector<pair<int, int>> fire{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int bfs() { 
    queue<pair<int, int>> q{};
    queue<pair<int, int>> flame{};

    q.push(start);

    for (int i = 0; i < fire.size(); i++){

        flame.push(fire[i]);
    }
    int result = 0;

    while (!q.empty()) {
        //��
        size_t flameSize = flame.size();
        for (int i = 0; i < flameSize; i++) {
            int y = flame.front().first;
            int x = flame.front().second;
            flame.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (0 <= ny && ny < R && 0 <= nx && nx < C) {
                    if (map[ny][nx] == '.' || map[ny][nx] == 'J') {
                        map[ny][nx] = 'F';
                        flame.push({ ny, nx });
                    }
                }
            }
        }

        //����
        size_t curSize = q.size();
        for (int i = 0; i < curSize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            //���ڶ��� ���� ���
            if (y == 0 || y == R - 1 || x == 0 || x == C - 1) {
                return result + 1;
            }

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (0 <= ny && ny < R && 0 <= nx && nx < C && !visited[ny][nx]) {
                    if (map[ny][nx] == '.') {
                        visited[ny][nx] = true;
                        q.push({ ny, nx });
                    }
                }
            }
        }
        result++;
    }
    return -1;
}

void input_data() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> map[i];
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 'J')  start = { i, j };
            else if (map[i][j] == 'F') fire.push_back({ i, j });
        }
    }
}

void solution() {
    int result = bfs();
    if (result == -1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << result << endl;
    }
}


int main(void) {
    input_data();
    solution();
    return 0;
}