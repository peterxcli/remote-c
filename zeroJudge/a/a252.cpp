#include <iostream>
#include <string>

using namespace std;

int main() {
    int len[50][50][50];
    string text1, text2, text3;
    cin >> text1 >> text2 >> text3;
    int text1Len = text1.length(), text2Len = text2.length(), text3Len = text3.length();

    for (int i = 0; i <= text1Len; i++) len[i][0][0] = 0;
    for (int i = 0; i <= text2Len; i++) len[0][i][0] = 0;
    for (int i = 0; i <= text3Len; i++) len[0][0][i] = 0;

    for (int i = 1; i <= text1Len; i++) {
        for (int j = 1; j <= text2Len; j++) {
            for(int k = 1; k <= text3Len; k++) {
                if(text1[i-1] == text2[j-1] == text3[k-1]) len[i][j][k] = len[i-1][j-1][k-1]+1;
                else if(text1[i-1] == text2[j-1]) len[i][j][k] = max(len[i-1][j][k], len[i][j-1][k]);
                else if(text2[j-1] == text3[k-1]) len[i][j][k] = max(len[i][j-1][k], len[i][j][k-1]);
                else if(text1[i-1] == text3[k-1]) len[i][j][k] = max(len[i-1][j][k], len[i][j][k-1]);
                else len[i][j][k] = max(max(len[i-1][j][k], len[i][j-1][k]), len[i][j][k-1]);
            }
        }
    }
    cout << len[text1Len][text2Len][text3Len] << endl;
}