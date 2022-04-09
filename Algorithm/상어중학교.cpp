#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int SIZE = 20;
const int INF = 987654321;
const int MAX = 20;
const int EMPTY = -2;
const int BLACK = -1;
const int RAINBOW = 0;

typedef struct {
	int y, x;
} S_POS;

typedef struct {
	S_POS baseBlock;
	S_POS arr[MAX * MAX];
	int blockGroupSize;
	int rainbowCnt;
} S_BLACK;

int N{}, M{};
int board[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void input_data() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}

void gravity() {
	// �߷�
	for (int i = N - 2; i >= 0; i--) { 
		for (int j = 0; j < N; j++)	{
			if (board[i][j] <= BLACK) {
				continue;
			}

			int y = i;

			while (true) {
				if (y == N)	{
					break;
				}

				int cur = board[y][j];
				int next = board[y + 1][j];

				if (next != EMPTY) {
					break;
				}

				board[y + 1][j] = cur;
				board[y][j] = EMPTY;
				y++;
			}
		}
	}
}

void rotateBoard() {
	int tempBoard[MAX][MAX];

	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++) {
			tempBoard[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++) {
			board[N - (j + 1)][i] = tempBoard[i][j];
		}
	}
}

S_BLACK getS_BLACK(int y, int x, int color) {
	S_BLACK tempS_BLACK;
	tempS_BLACK.baseBlock = { INF, INF };
	tempS_BLACK.rainbowCnt = 0;

	int baseColor = board[y][x] == RAINBOW ? color : board[y][x];

	int tempBoard[MAX][MAX];

	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			tempBoard[i][j] = board[i][j] == RAINBOW ? color : board[i][j];
		}
	}

	queue<S_POS> q;
	q.push({ y, x });
	visited[y][x] = true;
	int arrIdx = 0;

	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		// ��������� ��
		if (board[curY][curX] == RAINBOW)
		{
			tempS_BLACK.rainbowCnt++;
		}

		// ���� ����� ������ ����� �ƴ� ��� �߿��� ���� ��ȣ�� ���� ���� ���,
		// �׷��� ����� �������� ���� ��ȣ�� ���� ���� ����̴�.
		if (board[curY][curX] != RAINBOW
			&& (tempS_BLACK.baseBlock.y > curY
				|| (tempS_BLACK.baseBlock.y == curY && tempS_BLACK.baseBlock.x > curX)))
		{
			tempS_BLACK.baseBlock = { curY, curX };
		}

		// ����� �׷쿡 �߰�
		tempS_BLACK.arr[arrIdx++] = { curY, curX };

		for (int k = 0; k < 4; k++) {
			int nextY = curY + dy[k];
			int nextX = curX + dx[k];

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || tempBoard[nextY][nextX] <= BLACK) continue;
			// ���� ������ �ƴ϶��
			if (tempBoard[nextY][nextX] != baseColor) continue;
			if (visited[nextY][nextX]) continue;

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX });
		}
	}

	tempS_BLACK.blockGroupSize = arrIdx;
	if (tempS_BLACK.rainbowCnt == arrIdx) {
		tempS_BLACK.blockGroupSize = 0;
	}

	return tempS_BLACK;
}

int getScore() {
	S_BLACK blockGroup;
	blockGroup.rainbowCnt = 0;
	blockGroup.blockGroupSize = 0;
	blockGroup.baseBlock = { INF, INF };

	for (int y = 0; y < N; y++)	{
		for (int x = 0; x < N; x++)	{
			if (board[y][x] <= BLACK) {
				continue;
			}

			// ������ ����� �� ���򸶴� �����Ͽ� ����
			for (int color = 1; color <= M; color++) {
				memset(visited, false, sizeof(visited));

				S_BLACK tempS_BLACK = getS_BLACK(y, x, color);

				if (tempS_BLACK.blockGroupSize < 2) {
					continue;
				}

				// ũ�Ⱑ ���� ū ��� �׷��� ã�´�
				if (tempS_BLACK.blockGroupSize > blockGroup.blockGroupSize) {
					blockGroup = tempS_BLACK;

					continue;
				}

				// �׷��� ��� �׷��� ���� ����� ���Ե� ������ ����� ���� ���� ���� ��� �׷�
				if (tempS_BLACK.blockGroupSize == blockGroup.blockGroupSize)	{
					if (tempS_BLACK.rainbowCnt > blockGroup.rainbowCnt) {
						blockGroup = tempS_BLACK;

						continue;
					}

					// �׷��� ��ϵ� ��������� ���� ����� ���� ���� ū ����, �� �͵� �������̸� ���� ���� ū ���� ã�´�
					if (tempS_BLACK.rainbowCnt == blockGroup.rainbowCnt)	{
						if (blockGroup.baseBlock.y < tempS_BLACK.baseBlock.y
							|| (blockGroup.baseBlock.y == tempS_BLACK.baseBlock.y
								&& blockGroup.baseBlock.x < tempS_BLACK.baseBlock.x)) {
							blockGroup = tempS_BLACK;
						}
					}
				}
			}
		}
	}

	// �׷쿡 ���� ����� ������ 2���� ũ�ų� ���ƾ��ϸ�
	if (blockGroup.blockGroupSize < 2) return 0;

	for (int i = 0; i < blockGroup.blockGroupSize; i++) {
		board[blockGroup.arr[i].y][blockGroup.arr[i].x] = EMPTY;
	}
	return blockGroup.blockGroupSize * blockGroup.blockGroupSize;
}

void solution() {
	/*
	1) ũ�Ⱑ ���� ū ��� �׷��� ã�´�. 
		�׷��� ��� �׷��� ���� ����� ���Ե� ������ ����� ���� ���� ���� ��� �׷�, 
		�׷��� ��ϵ� ��������� ���� ����� ���� ���� ū ����, �� �͵� �������̸� ���� ���� ū ���� ã�´�.
	2) 1���� ã�� ��� �׷��� ��� ����� �����Ѵ�. 
		��� �׷쿡 ���Ե� ����� ���� B��� ���� ��, B2���� ȹ���Ѵ�.
	3) ���ڿ� �߷��� �ۿ��Ѵ�.
	4) ���ڰ� 90�� �ݽð� �������� ȸ���Ѵ�.
	5) �ٽ� ���ڿ� �߷��� �ۿ��Ѵ�.
	*/
	int result = 0;
	while (true) {
		int score = getScore();
		if (score == 0)	break;
		result += score;
		gravity();
		rotateBoard();
		gravity();
	}

	cout << result << "\n";
}

int main() {
	input_data();
	solution();
	return 0;
}