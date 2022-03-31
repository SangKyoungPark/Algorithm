/*
Q)	����̰� ��� ������ �����ϱ� ���� Ÿ���ϴ� ����� �ּ� ����

S)	1. ������ �� N / ����� ���� M
	2. M�� �� a,b (a-b)�պ��ϴ� �����

A)	1. N M �Է�
	2. a,b (m�� ����)
	3. airplane[N] / �� �迭�� �°� idx -> ����� �� ã��
	4. MST �˰���
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define SIZE 1010
#define INF 987987987

int N{}, M{};
vector <int> v[SIZE]{};
bool check[SIZE]{};

void input_data() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		v[i].clear();
		check[i] = false;
	}
	for (int i = 0; i < M; i++) {
		int a{}, b{};
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void solution() {
	int nRes = 0;
	queue <int> q{};

	q.push(1);
	check[1] = true;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();

		size_t size = v[cidx].size();
		for (int i = 0; i < size; i++) {
			int next = v[cidx][i];
			if (!check[next]) {
				check[next] = true;
				nRes++;
				q.push(next);
			}
		}
	}
	cout << nRes << endl;
}


int main() {
	int tc{};
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		input_data();
		solution();
	}
	return 0;
}