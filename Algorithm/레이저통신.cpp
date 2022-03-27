/*
Q)  �ſ��� �ּҰ��� ���ض�

S)  1. �ѹ��� ��ĭ �� �̵�

A)  1. �� �Է�
    2. BFS Ž�� -> ����ٲܶ� +1
        2-1) 90�� �� ȸ����ų �� �ִ�.
*/

#include <iostream>
#include <queue>
using namespace std;

#define SIZE 110

int W{}, H{};
int ey{}, ex{};
char map[SIZE][SIZE]{};
int dist[SIZE][SIZE]{};

queue <pair<int, int>> q{};

int dy[] = { 0, 1, 0, -1 };
int dx[] = { -1, 0, 1, 0 };


void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            while (0 <= ny && ny < H && 0 <= nx && nx < W && map[ny][nx] != '*') {
                if (!dist[ny][nx]) {
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push(make_pair( ny, nx ));
                }
                ny += dy[i];
                nx += dx[i];
            }
        }
    }
}

void input_data() {
    cin >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> map[i][j];
            //init
            if (map[i][j] == 'C') {
                if (ey == -1) {
                    ey = i;
                    ex = j;
                }
                else {
                    q.push(make_pair(i, j));
                }
            }
        }
    }
}

void solution() {
    bfs();
    cout << dist[ey][ex] - 1;
}

void init() {
    ey = -1;
}

int main() {
    init();
    input_data();
    solution();
    return 0;
}