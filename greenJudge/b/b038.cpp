#include <iostream>
#include <string>
using namespace std;

void print(int cur, string rec);
void swap(string &str, int i, int j);

string numberTable = "123456789";
int N;
bool used[9] = {false};

int main() {
    cin >> N;
    print(0, "");
}

void print(int cur, string rec) {
    if(cur == N) {
        cout << rec << endl;
        return;
    }
    else {
        for(int i = 0; i < N; i++){
            if(!used[i]) {
                used[i] = true;
                print(cur+1, rec+numberTable[i]);
                used[i] = false;
            }
            
        }
    }
}
