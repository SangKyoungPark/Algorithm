/*
# 3085 ��������.cpp
Q) ����̰� ���� �� �ִ� ���� �ִ� ����
A)	1. ���� ���� �ٸ� ������ ��ĭ ����
	2. ���� ��ĭ�� ����ִ� ���� ���� ��ȯ
	3. ��� ���� ������ �̷���� �ִ� ���� ��κ�(��or��) ���� �Դ´�.
	(* ���� ��κи� 1�� �Դ´�.)

	�� ���¸��� �ִ� ���̰� �������� �˾ƾ��� 
		-> ���������� �� �������� �ִ밪 �Ǵ�
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define SIZE 52

int n{};
char map[SIZE][SIZE]{};
bool visited[SIZE][SIZE]{};

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void input_data() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

int getMaxLength() {
	int myMax = -1;

	for (int i = 0; i < n; i++) {
		// �� �˻�
		int len = 1;
		char pivot = map[i][0];
		for (int j = 1; j < n; j++) {
			if (pivot == map[i][j]) {
				len++;
			}
			else {
				pivot = map[i][j];
			}
		}
		myMax = max(myMax, len);

		// ���˻�
		len = 1;
		pivot = map[0][i];
		for (int j = 1; j < n; j++) {
			if (pivot == map[j][i]) {
				len++;
			}
			else {
				pivot = map[j][i];
			}
		}
		myMax = max(myMax, len);
	}
	return myMax;
}

void solution() {
	memset(visited, false, sizeof(visited));
	int myMax = getMaxLength();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = true;
			//0,0 ~ n-1,n-1 ���� ���鼭 �ٲ� -> �����Ǵ� -> ����ġ
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n)	continue;
				if (!visited[ny][nx] && map[ny][nx] != map[i][j]) {
					swap(map[ny][nx], map[i][j]);
					myMax = max(myMax, getMaxLength());
					swap(map[i][j], map[ny][nx]);
				}
			}
		}
	}
	cout << myMax << endl;
}

int main() {	
	//input
	input_data();

	//solution
	solution();
	
	return 0;
}