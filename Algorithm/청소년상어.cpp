/*
# Q
- �� ���� �� �ִ� ����� ��ȣ�� ���� �ִ밪��?

# Algo
1. �� set -> ��ȣ, ����
2. ��� ��ġ�ϸ鼭 1���� ����
3. ����� ��� �̵��ϴ� �ùķ��̼�
    - �̵��� ��, ������ ������ ��ġ�� �ٲٴ� ����� ���
4. �� ��Ƹ��� -> 3������ �ݺ�

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct {
    int x, y, dir;
    bool dead;
}FISH;

FISH fishArr[16]; // ����� ��ȣ�� �ε���, ������� ��ġ �� ���� ���� �迭
int arr[4][4];    // �� �迭 �� ��Ʈ���� ����� ��ȣ ��Ÿ��
                  // FISH�� �迭�� 4*4 �迭�� ������ ��ȣ��, -1�� ��ġ�� ����� ����, -2�� ��ġ�� ��� ����
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int maxFeed = 0;

bool available(int x, int y) { return x >= 0 && y >= 0 && x < 4 && y < 4; }

void move_fish() {
    for (int i = 0; i < 16; i++) {
        // 1. 1�� �������� 16�� �������� ��� ����� �̵� ����
        bool move = false;
        int cnt = 0;
        int x = fishArr[i].x;
        int y = fishArr[i].y;
        if (arr[x][y] < 0 || fishArr[i].dead) continue; // ����Ⱑ �װų� �� ��ġ�� �迭�� ��� ����

        while (!move && cnt <= 8) { // �̵� ������ ���, ����⸦ �̵��ϰ� while���� ��������
            cnt++;
            if (move) break;
            // 2. ������ �̵��� �� ���������� 8-������ ��ȯ�ذ��� �ݺ�
            int nx = x + dx[fishArr[i].dir];
            int ny = y + dy[fishArr[i].dir];

            if (available(nx, ny) && arr[x][y] >= 0 && arr[nx][ny] != -2) {
                if (arr[nx][ny] >= 0) {
                    // 3. ���� �ش� ��ġ�� �ٸ� ����Ⱑ ���� ��, ���� ������ �ش� ��ġ�� ����⸦ ���� �ٲ�
                    move = true;
                    swap(fishArr[arr[nx][ny]].x, fishArr[i].x);
                    swap(fishArr[arr[nx][ny]].y, fishArr[i].y);
                    swap(arr[x][y], arr[nx][ny]);
                    break;
                }
                else if (arr[nx][ny] == -1) {
                    // 4. �ش� ��ġ�� ������� ��, ���� ����⸦ �ش� ��ġ�� �ű�
                    move = true;
                    fishArr[i].x = nx;
                    fishArr[i].y = ny;
                    swap(arr[x][y], arr[nx][ny]);
                    break;
                    // *�ݷ�: N��°�� ����Ⱑ ����ִ� N+1��° ������� ĭ���� �̵����� ��,
                    //i=N+1�� �ݺ������� �ѹ� �̵��� ����Ⱑ �ٽ� �̵��� �� �ֱ⿡ ����ó��
                }
            }
            else { // 5. �̵� �Ұ����� ���, ����� ������ �ϳ� ȸ���ϰ� �ٽ� �ݺ� ����
                fishArr[i].dir = (fishArr[i].dir + 1) % 8;
            }
        }
    }
}

void copy_arr(int fromArr[][4], int toArr[][4], FISH fromFish[], FISH toFish[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            toArr[i][j] = fromArr[i][j];
            toFish[4 * i + j] = fromFish[4 * i + j];
        }
    }
}

void dfs_shark(int nx, int ny, int feed, int fdir) {
    // 1. �ش� ��ġ�� �� ���� �ش� ������� ������ ����
    maxFeed = max(maxFeed, feed);

    FISH tmpFishArr[16];
    int tmpArr[4][4];
    copy_arr(arr, tmpArr, fishArr, tmpFishArr);
    // 2. ��Ƴ��� ����⿡ ����, ��� ������ �̵�
    move_fish();

    // 3. �ش� ���⿡�� �� �� �ִ� ��� ��쿡 ����, �ٽ� ��������� Ž����
    int nextX = nx;
    int nextY = ny;
    for (int i = 0; i < 3; i++) {
        nextX += dx[fdir];
        nextY += dy[fdir];
        if (!available(nextX, nextY)) {
            break;
        }
        else {
            if (arr[nextX][nextY] != -1) {
                int tmpNum = arr[nextX][nextY];
                int tmpDir = fishArr[tmpNum].dir;
                arr[nx][ny] = -1;
                arr[nextX][nextY] = -2;
                fishArr[tmpNum].dead = true;
                dfs_shark(nextX, nextY, feed + tmpNum + 1, tmpDir);
                fishArr[tmpNum].dead = false;
                arr[nextX][nextY] = tmpNum;
                arr[nx][ny] = -2;
                // 4. ��� ȣ�⿡�� �������� ���� ����� ���¸� ������ ����
            }
        }
    }
    copy_arr(tmpArr, arr, tmpFishArr, fishArr);
}

int main() {
    //input
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int dir;
            cin >> arr[i][j]; // ������� ��ġ
            arr[i][j]--;
            cin >> dir; // ������� ����
            FISH tmpFish{ i, j, dir - 1, false };
            fishArr[arr[i][j]] = tmpFish;
        }
    }
    //init
    int tmpNum = arr[0][0];
    int tmpDir = fishArr[arr[0][0]].dir;
    fishArr[arr[0][0]].dead = true;
    arr[0][0] = -2; // DFS�Լ��� �θ� ��, �� �� ���� ����� �迭�� ���� �ش� ��ġ�� �� ��

    //logic
    dfs_shark(0, 0, tmpNum + 1, tmpDir); // ������� ũ��� ������ ������

    //result
    cout << maxFeed << endl;
    return 0;
}
