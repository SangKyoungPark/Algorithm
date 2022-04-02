/*
Q)	2���� �˼��� Ż����Ű�� ���� ����� �ϴ� ���� ���� ���ض�

S)	1. H / W <= 100
	2. ����� . | �� * | �� # | �˼� $

A)	1. tc -> map �Է�
	2. �ۿ��� ������ ��η� �Ǵ�
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

char prison[102][102]{};
int min_door[3][102][102]{};
int height{}, width{};
pair<int, int> prisoner[2]{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

struct VertexInfo {
    int r;
    int c;
    int cost;

    bool operator<(const VertexInfo& x)const {
        return cost > x.cost;
    }
};

void Dijkstra(int person_idx, int start_r, int start_c) {
    priority_queue<VertexInfo> pq;
    pq.push({ start_r, start_c, 0 });
    min_door[person_idx][start_r][start_c] = 0;

    int r, c, cost, next_r, next_c, next_cost;
    char next_state;
    while (!pq.empty()) {
        r = pq.top().r;
        c = pq.top().c;
        cost = pq.top().cost;
        pq.pop();

        if (min_door[person_idx][r][c] < cost)
            continue;

        for (int i = 0; i < 4; ++i) {
            next_r = r + dy[i];
            next_c = c + dx[i];

            if (next_r < 0 || height + 1 < next_r || next_c < 0 || width + 1 < next_c)  //���� Ȯ��
                continue;

            next_state = prison[next_r][next_c];
            next_cost = cost;

            if (next_state == '*') //���̶�� �׳� �Ѿ
                continue;
            else if (next_state == '#')  //���̶�� cost�� ����
                next_cost++;

            if (next_cost < min_door[person_idx][next_r][next_c]) {
                pq.push({ next_r, next_c, next_cost });
                min_door[person_idx][next_r][next_c] = next_cost;
            }
        } //for end
    } //while end

}

int main() {
    int test_num;
    cin >> test_num;

    while (test_num--) {
        cin >> height >> width;

        int order = 0;
        string st;
        for (int r = 1; r <= height; ++r) {
            cin >> st;
            st = '.' + st + '.';
            for (int c = 0; c <= width + 1; ++c) {
                prison[r][c] = st[c];
                if (prison[r][c] == '$')
                    prisoner[order++] = { r,c };
            }
        }

        for (int c = 0; c <= width + 1; ++c) {
            prison[0][c] = '.';
            prison[height + 1][c] = '.';
        }

        memset(min_door, 0xf, sizeof(min_door));  //0xf�� �ʱ�ȭ ������.
        Dijkstra(0, 0, 0);
        Dijkstra(1, prisoner[0].first, prisoner[0].second);
        Dijkstra(2, prisoner[1].first, prisoner[1].second);

        int min_open_num = INT32_MAX;
        int opened_doors;
        for (int r = 0; r <= height + 1; ++r) {
            for (int c = 0; c <= width + 1; ++c) {
                if (prison[r][c] == '*')
                    continue;

                opened_doors = min_door[0][r][c] + min_door[1][r][c] + min_door[2][r][c];
                if (prison[r][c] == '#') //�ش� ��ǥ�� ���� ���
                    opened_doors -= 2;
                min_open_num = min(opened_doors, min_open_num);
            }
        }

        cout << min_open_num << '\n';
    }

    return 0;
}