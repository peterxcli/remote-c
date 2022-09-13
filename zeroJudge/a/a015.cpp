#include <iostream>

using namespace std;

int main() {
    int row, column, matrix[100][100];
    while(cin >> row >> column) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                cin >> matrix[i][j];
            }
        }

        for(int i = 0; i < column; i++) {
            for(int j = 0; j < row; j++) {
                cout << matrix[j][i] << (j!=row-1?" ":"");
            }
            cout << endl;
        }

    }

}