/*
Q)	���� ������ �ּҷ� �ϱ� ���� �ʿ��� �ּ� �̵�Ƚ���� ���ض�

S)	1. ���� ������������ ������ ���� �پ���� �� �ִ�.
	2. �� ���� ���� ĭ���� �̵��ϴ� �� �� ���
	3. ������  ���� ����ĭ�� ������  �� �������� ���ŵ�

A)  1. ���� üũ
    2. dfs ����
        2-1. o�ƴϸ� �ݺ� -> o ����ĭ ��ĭ���� üũ
        2-2. �̵� -> Ž�� -> ����
*/
#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;

const int row = 5;
const int col = 9;

int ansPin{};
int ansMove{};
char map[10][10]{};
int pinNum{};

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void dfs(int y, int x, int pinNum, int depth) {
    if (pinNum <= ansPin) {
        if (pinNum == ansPin) {
            ansMove = (ansMove > depth ? depth : ansMove);
        }
        else {
            ansPin = pinNum; ansMove = depth; 
        }
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // ����ĭ ����üũ
        if (ny >= 0 && ny < row && nx >= 0 && nx < col) {
            // 'o'�� �ƴϸ� �����ݺ�
            if (map[ny][nx] != 'o') continue;
            // 'o'�� �״���ĭ ��ĭ���� üũ�ϰ� �̵�
            int nny = ny + dy[i];
            int nnx = nx + dx[i];
            // �ٴ���ĭ ����üũ
            if (nny >= 0 && nny < row && nnx >= 0 && nnx < col) {
                if (map[nny][nnx] == '.') {
                    //�̵�
                    map[y][x] = map[ny][nx] = '.';
                    map[nny][nnx] = 'o';
                    // 0, 0���� Ž���� ������Ѵ�.
                    for (int i = 0; i < row; i++)
                        for (int j = 0; j < col; j++)
                            if (map[i][j] == 'o')
                                dfs(i, j, pinNum - 1, depth + 1);
                    // ����
                    map[y][x] = map[ny][nx] = 'o';
                    map[nny][nnx] = '.';
                }
            }
        }
    }
}
void solution() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (map[i][j] == 'o') {
                dfs(i, j, pinNum, 0);
            }
        }
    }
    printf("%d %d\n", ansPin, ansMove);
}

void input_data() {
    pinNum = 0;
    ansPin = ansMove = MAX;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'o') pinNum++;
        }
    }
}
int main(void) {
    int T{};
    cin >> T;
    for (int t = 0; t < T; t++) {
        input_data();
        solution();
    }
}
