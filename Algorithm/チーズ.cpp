/*
Q)  ġ� ������� �����鼭 �̵��ϴ� �ִܰŸ�

S)  1. ��湮 ����
    2. ���� ���� ġ����� �Ծ�鼭 �̵��ؾ���

A)  1. ���Է�
    2. N��, BFS ( ������ -> 1�� -> 2��ġ�� ������� �ȳ�)
    3. �ٽ� BFS �Ҷ�����, check[][]�ʱ�ȭ
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define SIZE 1010

struct S_POS {
    int y{};
    int x{};
    int dir{};
};

int R{}, C{}, N{};
int my{}, mx{}, nRes{}, hp = 1;
char map[SIZE][SIZE]{};
bool check[SIZE][SIZE]{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };


void bfs() {
    queue <S_POS> q{};

    q.push({ my, mx, 0 });
    check[my][mx] = true;

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int d = q.front().dir;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (check[ny][nx] || map[ny][nx] == 'X') continue;

            if ('1' <= map[ny][nx] && map[ny][nx] <= '9') {
                if (hp >= map[ny][nx] - '0') {
                    hp++;
                    map[ny][nx] = '.';
                    nRes += (d + 1);
                    my = ny;
                    mx = nx;
                    return;
                }
            }
            q.push({ ny, nx, d + 1 });
            check[ny][nx] = true;
        }
    }
}

void input_data() {
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                my = i;
                mx = j;
            }
        }
    }
}

void solution() {
    for (int i = 0; i < N; i++) {
        memset(check, false, sizeof(check));
        bfs();
    }
    cout << nRes << endl;
}

int main() {
    input_data();
    solution();    
    return 0;
}
