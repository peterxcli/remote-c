#include <iostream>
#include <string>
using namespace std;
void print(int cur, string rec);

string numberTable = "0123456789";
int passwordLen, Max;

int main() {
    cin >> passwordLen >> Max;
    print(0, "");
}

void print(int cur, string rec) {
    if(cur == passwordLen) {
        cout << rec << endl;
        return;
    }
    else {
        for(int i = 0; i < Max; i++)
            print(cur+1, rec+numberTable[i]);
    }
}