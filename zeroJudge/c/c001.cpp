#include <iostream>
#include <string>

using namespace std;

int main() {
    int len[105][105];
    string text1, text2;
    while(cin >> text1 >> text2) {
        int text1Len = text1.length(), text2Len = text2.length();

        for (int i = 0; i <= text1Len; i++) len[i][0] = 0;
        for (int i = 0; i <= text2Len; i++) len[0][i] = 0;

        for (int i = 1; i <= text1Len; i++) {
            for (int j = 1; j <= text2Len; j++) {
                if(text1[i-1] == text2[j-1]) 
                    len[i][j] = len[i-1][j-1]+1;
                else
                    len[i][j] = max(len[i-1][j], len[i][j-1]);
            }
        }
        cout << len[text1Len][text2Len] << endl;
        text1.clear(), text2.clear();
    }
}