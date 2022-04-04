/*
Q)	��� ĭ�� �湮�ϱ� ���� �̵� Ƚ��(����Ʋ��) �ּҰ� ���ϱ�

S)	1. N, M <= 30

A)	1. DFS -> ����ٲ� �� cnt ++ (��ι湮üũ)

����) https://dmzld.tistory.com/33
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define SIZE 32
#define INF 987987987

int N{}, M{}, K{};
char map[SIZE][SIZE]{};
bool visited[SIZE][SIZE]{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int ans;

void dfs(int y, int x, int cnt, int k) {
	// �����̳��� �ð� ���̱�
	if (ans < cnt)	return;

	// ��� Ž���� ��쿡 ans ����
	if (k == 0) {
		if (ans > cnt)	ans = cnt;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		int nk = k;
		// ���� �������� Ž���� �� ���� �� ���� Ž��
		while (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == '.' && !visited[ny][nx]) {
			visited[ny][nx] = true;
			nk--;
			ny += dy[i];
			nx += dx[i];
		}
		ny -= dy[i];
		nx -= dx[i];

		if (ny != y || nx != x) {
			dfs(ny, nx, cnt + 1, nk);
			// �̹� �ݺ������� Ž���� ���� �ǵ�����
			while (ny != y || nx != x) {
				visited[ny][nx] = false;
				ny -= dy[i];
				nx -= dx[i];
			}
		}
	}
}

int main() {
	int T = 1;
	while (cin >> N >> M) {
		// init
		ans = INF;
		K = 0;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				if (map[i][j] == '.')
					K++; // Ž���Ǿ���� ������ ��
			}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == '.') {
					visited[i][j] = true;
					dfs(i, j, 0, K - 1); // ��� ����
					visited[i][j] = false;
				}
			}
		}

		if (ans == INF)
			cout << "Case " << T << ": " << -1 << "\n";
		else
			cout << "Case " << T << ": " << ans << "\n";

		T++;
	}

	return 0;
}