#include<iostream>
#include<cstring>
using namespace std;
char id[20];
int idhead[26] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
int check(int N){
    int sum = 0;                                          
    for(int i = 0; i < strlen(id) - 1; i++){
        sum += (id[i] - '0') * (8 - i);
    }
    sum += (idhead[N] % 10) * 9 + (idhead[N] / 10);
    if((10 - (sum % 10)) % 10 == id[8] - '0') {
        return 1;
    }
    else {
        return 0;   
    }
}
int main() {
    while (cin >> id){
        char head = 'A';
        for(int i = 0; i < 26; i++){
            if(check(i)){
                cout << (char)(head + i);
            }
        }
        cout << endl;
    }
}