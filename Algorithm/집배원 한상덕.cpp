
/*
- 3s / 256 MB
- ��ü�� : P / �� : K / ������ : .
- ��� P���� ���� ����, ����, �밢�� ������ ĭ�̵�����
- ��� �� -> ��ü������ ���ƿ;� �Ѵ�.
- (������ - ������) => �Ƿε� 
- ���� ���� �Ƿε��� ��� ���� ����Ϸ���??
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>


#define SIZE 52

int n{};
char map[SIZE][SIZE]{};
int high[SIZE][SIZE]{};

int px{}, py{};
int dy[] = { -1,-1,-1,0,1,1,1,0 };
int dx[] = { -1,0,1,1,1,0,-1,-1 };
int cnt{};

int myMin = 987987987;

void input_data() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'K')	cnt++;
			else if (map[i][j] == 'P') {
				py = i;
				px = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &high[i][j]);
		}
	}
}

void dfs(int y, int x, int sum ,int k) {
	if (k == 0) {
		myMin = min(myMin, sum);
		return;
	}
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)	continue;
		
	}
}

int solution() {

	// ��� ��Ʈ�� �� �����鼭 ���� ���� return -> �� �� ������ ���� ����
	for (int i = 0; i < 8; i++) {
		dfs(py, px, 0, cnt);
	}
	// ��� ��ȸ�� ���Ƽ� �;� �� -> ����


	return 0;
}

int main() {
	//init
	cnt = 0;

	//input
	input_data();

	//solve
	int nRes = solution();

	//result
	printf("%d\n", nRes);
	
	return 0;
}