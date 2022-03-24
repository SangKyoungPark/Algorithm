/*
Q)	���� ª�� ����� ���� ���(Ÿ���� ����)

S)	1. ù��° ���� Ÿ�� ��ȣ : 1 / ������ Ÿ�� ��ȣ : N
	2. �ι��� �ٿ��� ùŸ���� ��ȣ N+1 / ������ 2 * N - 1 

A)	1. �Է�
	2. BFS
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define SIZE 501

struct S_TILE {
    int value;
    int num;
    int dist;
};
S_TILE map[SIZE][SIZE * 2]{};
int path[SIZE * SIZE]{};
int N{};

int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };

vector<int> way{};
int last = 1;

void bfs() {
    queue<pair<int, int>> q{};
    
    //init
    q.push({ 1,1 });
    q.push({ 1,2 });
    map[1][1].dist = 1;
    map[1][2].dist = 1;
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int col = nr % 2 == 1 ? N : N - 1;
            int start = nr % 2 == 1 ? 1 : 2;

            if (nr < 1 || nr > N || nc < start || nc > (col * 2) + (start - 1)) continue;
            if (map[nr][nc].dist != 0) continue;
            if (map[nr][nc].value != map[r][c].value) continue;

            //Ÿ���� ������ (����,������) �Ÿ��� ���ƾ��Ѵ�.
            //���� ������ ���� Ÿ���϶� ������ �Ÿ��� ���ʿ� �־��ְ�,
            //������ ť�� �־��ش�.
            bool left = false;

            if (map[nr][nc - 1].num == map[nr][nc].num) {
                left = true;
            }
            map[nr][nc].dist = map[r][c].dist + 1;
            q.push({ nr,nc });

            //������ ���� Ÿ��
            if (left) {
                map[nr][nc - 1].dist = map[nr][nc].dist;
                q.push({ nr,nc - 1 });
            }
            //�������� ���� Ÿ��
            else {
                map[nr][nc + 1].dist = map[nr][nc].dist;
                q.push({ nr,nc + 1 });
            }
            //���±��� ������ Ÿ�ϵ��� �˱� ���� ���� Ÿ���� �������ش�.
            path[map[nr][nc].num] = map[r][c].num;

            //��ȣ�� ū Ÿ�� ã��
            if (last < map[nr][nc].num) {
                last = map[nr][nc].num;
            }
        }
    }
}
void findPath() {
    //��ȣ�� ���� ū Ÿ�� ã�Ƽ� �Դ� �� �ǵ��� ����
    int temp = last;
    way.push_back(temp);
    while (path[temp] != 0) {
        way.push_back(path[temp]);
        temp = path[temp];
    }
    cout << way.size() << endl;
    for (int i = (int)way.size() - 1; i >= 0; i--) {
        cout << way[i] << " ";
    }
    cout << endl;
}

void input_data() {
    cin >> N;
    int cnt = 1;
    for (int i = 1; i <= N; i++) {
        int col = i % 2 == 1 ? N : N - 1;
        int start = i % 2 == 1 ? 1 : 2;

        for (int j = start; j <= (col * 2) + (start - 1); j++) {
            cin >> map[i][j].value;
            map[i][j].num = (cnt + 1) / 2;
            cnt++;
        }
    }
}

void solution() {
    bfs();
    findPath();
}

int main() {
    input_data();
    solution();
    return 0;
}