/*
# 3967 ���� ��Ÿ

Q)   ���� �� ä���� ���� ��Ÿ �����

S)   1. �� 6���� ������ ���� �����ؾ� ��
   2. 2���� ��ġ�� ���ڵ��� �� 6��
   3. ���� �� 12�� A~L����

A)   1. �ʿ� �ִ� ���� ���

*/
#include <iostream>
using namespace std;
#define SIZE 10

int map[SIZE][SIZE]{};

void input_data() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            char cData;
            cin >> cData;
            //init
            if (cData == '.') {
                map[i][j] = -1;
            }
            else if (cData == 'x') {
                map[i][j] = 0;
            }
            else {
                map[i][j] = cData - 64;
            }
        }
    }
}

void solution() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {

    input_data();
    
    solution();
    
    return 0;
}