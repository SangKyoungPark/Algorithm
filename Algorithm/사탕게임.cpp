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
#include <string>
using namespace std;
#define SIZE 52

int n{};
char map[SIZE][SIZE]{};
bool visited[SIZE][SIZE]{};

void input_data() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

int getMaxLength() {
	int maxLen = 1;
	// �¿� 
	for (int i = 0; i < n; i++)	{
		int len = 1;
		for (int j = 1; j < n; j++)
			if (map[i][j - 1] == map[i][j])
				len++;
			else {
				maxLen = max(maxLen, len);
				len = 1;
			}
		maxLen = max(maxLen, len);
	}
	// ����
	for (int i = 0; i < n; i++)	{
		int len = 1;
		for (int j = 0; j < n - 1; j++)
			if (map[j + 1][i] == map[j][i])
				len++;
			else {
				maxLen = max(maxLen, len);
				len = 1;
			}
		maxLen = max(maxLen, len);
	}

	return maxLen;
}

void solution() {
	int myMax = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			//�� �� swap
			swap(map[i][j], map[i][j + 1]);
			myMax = max(myMax, getMaxLength());
			swap(map[i][j], map[i][j + 1]);
			//�� �Ʒ� swap
			swap(map[j][i], map[j + 1][i]);
			myMax = max(myMax, getMaxLength());
			swap(map[j][i], map[j + 1][i]);
		}
	}
	//result
	cout << myMax << "\n";
}

int main() {	
	//input
	input_data();

	//solution
	solution();
	
	return 0;
}