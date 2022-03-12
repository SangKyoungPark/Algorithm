#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int N, M, Fuel; // Fuel: �ܿ����ᷮ
int arr[21][21];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

typedef struct {
    int idx, x, y, dist, dest; // dist:�ýÿ��� �Ÿ�, dest:������������ �Ÿ�
} USER;
vector<USER> userVec;
vector<pair<int, int>> destVec;
int taxiX, taxiY;

bool available(int x, int y) { return x > 0 && y > 0 && x <= N && y <= N && arr[x][y] == 0; }

typedef struct {
    int x, y, d;
} ELEM;

int get_dest_bfs(int i) {
    queue<ELEM> bfsQ;
    bfsQ.push(ELEM{ userVec[i].x, userVec[i].y, 0 });
    bool visit[21][21] = { 0, };

    while (!bfsQ.empty()) {
        ELEM qTop = bfsQ.front();
        bfsQ.pop();

        if (qTop.x == destVec[i].first && qTop.y == destVec[i].second) return qTop.d;
        else {
            for (int j = 0; j < 4; j++) {
                int nx = qTop.x + dx[j];
                int ny = qTop.y + dy[j];
                if (available(nx, ny) && !visit[nx][ny]) {
                    bfsQ.push(ELEM{ nx, ny, qTop.d + 1 });
                    visit[nx][ny] = true;
                }
            }
        }
    }
    return -1;
}

void get_dist_to_dest() {
    // �� �մ��� ��ġ�������� ������������ �Ÿ��� �̸� ���
    for (int i = 0; i < M; i++) {
        userVec[i].dest = get_dest_bfs(i);
    }
}

int get_taxi_dist_bfs(int i) {
    queue<ELEM> bfsQ;
    bfsQ.push(ELEM{ userVec[i].x, userVec[i].y, 0 });
    bool visit[21][21] = { 0, };

    while (!bfsQ.empty()) {
        ELEM qTop = bfsQ.front();
        bfsQ.pop();

        if (qTop.x == taxiX && qTop.y == taxiY) return qTop.d;
        else {
            for (int j = 0; j < 4; j++) {
                int nx = qTop.x + dx[j];
                int ny = qTop.y + dy[j];
                if (available(nx, ny) && !visit[nx][ny]) {
                    bfsQ.push(ELEM{ nx, ny, qTop.d + 1 });
                    visit[nx][ny] = true;
                }
            }
        }
    }
    return -1;
}

bool cmp_user(USER& u1, USER& u2) {
    if (u1.dist == u2.dist && u1.x == u2.x) return u1.y < u2.y;
    else if (u1.dist == u2.dist) return u1.x < u2.x;
    else return u1.dist < u2.dist;
}

int start_taxi() {
    for (int i = 0; i < M; i++) {
        // 1. BFS�� �ý� to �ùΰŸ� ��� ����
        for (int j = 0; j < userVec.size(); j++) userVec[j].dist = get_taxi_dist_bfs(j);
        // 2. �ý�-�ùΰŸ�, ���ȣ, ����ȣ ������ ����
        sort(userVec.begin(), userVec.end(), cmp_user);
        // 3. �ܿ� ���ᷮ üũ�ؼ� ������ ���������� ���� ���ϸ� -1 ��ȯ
        if (userVec.front().dist + userVec.front().dest > Fuel) return -1;
        else if (userVec.front().dist == -1) return -1; // �ݷ�: ���� �Ұ����� �������� �ϳ��� �ִٸ� ������ �ýÿ��� �Ұ���
        else {
            // 4. ���� �����ϸ� �ܿ����ᷮ ������Ʈ �� ������ ��ȸ
            taxiX = destVec[userVec.front().idx].first;
            taxiY = destVec[userVec.front().idx].second;
            Fuel = Fuel - userVec.front().dist + userVec.front().dest;
            reverse(userVec.begin(), userVec.end());
            userVec.pop_back();
        }
    }
    return Fuel;
}

int main() {
    cin >> N >> M >> Fuel;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i + 1][j + 1];
        }
    }
    cin >> taxiX >> taxiY;

    for (int i = 0; i < M; i++) {
        USER user;
        cin >> user.x >> user.y;
        user.idx = i;
        userVec.push_back(user);
        int destX, destY;
        cin >> destX >> destY;
        destVec.push_back(pair<int, int>(destX, destY));
    }

    get_dist_to_dest();
    cout << start_taxi() << endl;

    return 0;
}