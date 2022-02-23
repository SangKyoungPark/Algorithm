#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 30

int r{}, c{};
char map[SIZE][SIZE]{};
bool visited[SIZE][SIZE]{};
int mr{}, mc{}, zr{}, zc{};
int br{}, bc{};
char block{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void init() {
    memset(visited, false, sizeof(visited));
}

void input_data() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'M') {
                mr = i;
                mc = j;
            }
            else if (map[i][j] == 'Z') {
                zr = i;
                zc = j;
            }
        }
    }
}

// ����� ������ ������ dfs ����
//        ������ ���⿡�� �� �� �ִ� �͸� . ��� �ٲ㼭 ����
void dfs(int y, int x, bool flag) {
    visited[y][x] = true;

    if (y == zr && x == zc) {
        return;
    }

    // flag �� ��ĭ�� 1�� �����ƴٴ� ǥ��
    if (flag) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= r || nx >= c)   continue;
            if (map[ny][nx] == '.') {
                cnt++;
                continue;
            }
        }
        if (cnt == 4)   return;
    }

    // ���� ��ġ�� �ִ� ��ȣ�� ���� Ž��
    // �ʺ��� -> dfs -> ���󺹱�
    if (map[y][x] == '|') {
        // �� + �Ʒ�
        // ������ �� �ִ� ��ȣ�� + 2 3
    }
    else if (map[y][x] == '-') {
        // �� + ����
        // ������ �� �ִ� ��ȣ�� + 1 2 3 4
    }
    else if (map[y][x] == '+') {
        // 4���� Ž��
        // ������ �� �ִ� ��ȣ�� | - + 1 2 3 4
    }
    else if (map[y][x] == '1') {
        // ���� + �Ʒ�
        // ������ �� �ִ� ��ȣ�� | - + 2 3 4
    }
    else if (map[y][x] == '2') {
        // �� + ���� 
    }
    else if (map[y][x] == '3') {
        // �� + ��
    }
    else if (map[y][x] == '4') {
        // �� + �Ʒ�
    }
}

void solution() {
    /*
    -> ��ĭ�� 7���� ��� ������
    BigO = 25 * 25 * 7
    M -> 4���⿡�� ���� �ִٸ� -> ������ -> dfs
                ���� ���ٸ� -> 7���� ��� ������ -> dfs
    */
    dfs(mr, mc, false);
}

int main() {

    init();

    input_data();

    solution();

    cout << br + 1 << bc + 1 << block << endl;
    return 0;
}