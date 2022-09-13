#include <iostream>
using namespace std;
#define MAX 105

int main() {
    int seq[MAX], len[MAX], N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> seq[i];
    for (int i = 0; i < N; i++) 
        len[i] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (seq[i] < seq[j])
                len[j] = max(len[j], len[i] + 1);
        }
    }
    int maxLen = 0;
    for (int i = 0; i < N; i++) 
        maxLen = max(maxLen, len[i]);
    cout << maxLen << endl;
}
