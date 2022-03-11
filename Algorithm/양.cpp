/*
# 3184 �� 

Q)	��ħ�� �������� �� ��Ƴ��� ��� ������ �� ���

S)	1. # ��Ÿ�� / o �� / v ����
	2. ���� �������θ� �̵�
	3. ��Ÿ���� ������ �ʰ� �ٸ�ĭ���� �̵��� �� �ִٸ� -> ��������
	4. �� �� > ���� �� (���� �̱�) otherwise, ������ �� ��� ��Ƹ���

A)	1. �Է� �� ��, ���� �� 
	2. ���� ���� Ž�� -> ��or���� -> BFS
	3. ��Ÿ�� �� �������� ��, ���� �� count
		3-1) �� > ���� -> ���� ���
		3-2) �� < ���� -> �� ���
	4. ��, ���� ���
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int MAX = 250;

int R{}, C{};
int sheep{}, wolf{};
string map[MAX]{};
bool visited[MAX][MAX]{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void BFS(int my, int mx) {
    int curSheep{}, curWolf{};
    queue <pair<int, int>> Q;

    Q.push({ my, mx });
    visited[my][mx] = true;

    if (map[my][mx] == 'o')   curSheep++;
    else if (map[my][mx] == 'v')  curWolf++;

    //���� ĭ �ȿ� �ִ� ��� ������ ���� ����
    while (!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if(!visited[ny][nx] && map[ny][nx] != '#') {
                visited[ny][nx] = true;
                if (map[ny][nx] == 'o') curSheep++;
                else if (map[ny][nx] == 'v')    curWolf++;
                Q.push({ ny, nx });
            }
        }
    }

    //���� �� ������ ���밡 �װ�
    if (curSheep > curWolf) wolf -= curWolf;
    //���� ���ų� ������ ���� �״´�
    else    sheep -= curSheep;
}

void input_data() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> map[i];
        for (int j = 0; j < C; j++)
            if (map[i][j] == 'o')
                sheep++;
            else if (map[i][j] == 'v')
                wolf++;
    }
}

void solution() {
    //logic
    //���� �湮���� ���� ĭ�̰� ���̳� ������ �� BFS ȣ��
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if ((map[i][j] == 'o' || map[i][j] == 'v') && !visited[i][j]) {
                BFS(i, j);
            }
        }
    }
    //result
    cout << sheep << " " << wolf << "\n";
}

int main(void) {
    input_data();

    solution();

    return 0;
}