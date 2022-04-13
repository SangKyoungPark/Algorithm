#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int N, K;
vector<vector<int>> board;


bool if_end() {
    // ����� ���� ���� ���������� ������ ��� true ��ȯ
    int max_fishes = *max_element(board[0].begin(), board[0].end());
    int min_fishes = *min_element(board[0].begin(), board[0].end());
    return ((max_fishes - min_fishes) <= K);
}


// ����� �̵� �Լ�
void move_fishes() {
    vector<vector<int>> new_board = board;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (board[y][x] == -1) continue;
            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx] == -1)
                    continue;
                // �� ��ǥ�� ���Ͽ� (�α� ��ǥ���� ��/5) ��ŭ ���� new_board�� ���
                // -> ��� ����ĭ�� ���Ͽ� ���ÿ� �߻��� �Ͱ� ���Ե�
                new_board[y][x] += (int)(board[ny][nx] - board[y][x]) / 5;
            }
        }
    }

    // ����� �̵� �� �ٽ� board�� ���ڷ� ���� (flat_bowl ���Ϳ� ���ʿ� ���� �߽ɿ� ����� ������� push)
    vector<int> flat_bowl;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if (new_board[y][x] == -1)
                continue;
            else
                flat_bowl.push_back(new_board[y][x]);
        }
    }
    //board�� �ʱ�ȭ �� �� board[0]�� flat_bowl�� ��ü
    board = vector<vector<int>>(N, vector<int>(N, -1));
    board[0] = flat_bowl; // board[0]�� flat_bowlf�� ����[
}

void move() {
    int ly = 1, lx = 1; // length y, length x
    int sx = 0; // start y, start x
    // 1. ����� �߰�
    int min_fishes = *min_element(board[0].begin(), board[0].end());
    for (int i = 0; i < N; ++i) {
        if (board[0][i] == min_fishes)
            board[0][i]++;
    }
    // 2. ������ ���� �����̱�
    while (sx + ly + lx <= N) {
        for (int y = 0; y < ly; ++y) {
            for (int x = 0; x < lx; ++x) {
                int ny = lx - x;
                int nx = sx + lx + y;
                board[ny][nx] = board[y][x + sx];
                board[y][x + sx] = -1;
            }
        }
        sx += lx;
        if (ly == lx) ly++;
        else lx++;


    }
    // 3. ����� �̵�
    move_fishes();

    // 4. �߽��� �������� ���� 2�� �̵�
    sx = 0;
    ly = 1;
    lx = N / 2;

    for (int i = 0; i < 2; ++i) {
        for (int y = 0; y < ly; ++y) {
            for (int x = 0; x < lx; ++x) {
                int ny = 2 * ly - y - 1;
                int nx = 2 * lx + sx - x - 1;
                board[ny][nx] = board[y][x + sx];
                board[y][x + sx] = -1;
            }
        }
        sx += lx;
        lx /= 2;
        ly *= 2;
    }
    // 5. ����� �̵�
    move_fishes();

}

int solve() {
    int count = 0;
    while (!if_end()) {
        count++;
        move();
    }
    return count;
}

int main() {
    cin >> N >> K;
    board = vector<vector<int>>(N, vector<int>(N, -1));
    for (int i = 0; i < N; ++i) {
        cin >> board[0][i];
    }
    cout << solve();
}
