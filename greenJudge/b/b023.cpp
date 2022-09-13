#include<iostream>
using namespace std;

void output(int n, char A, char B, char C);

int main(){
    int n;
    cin >> n;
    output(n, '1', '2', '3');
}

void output(int n, char A, char B, char C){
    if(n == 1)
        cout << "Ring " << n << " from " << A << " to " << C << endl;
    else
    {
        output(n - 1, A, C, B);
        cout << "Ring " << n << " from " << A << " to " << C << endl;
        output(n - 1, B, A, C);
    }
}

// void output(int n, char A, char B, char C){
//     if(n == 1)
//         cout << "Ring " << n << " from " << A << " to " << C << endl;
//     else
//     {
//         output(n - 1, '1', '3', '2');
//         output(1, '1', '2', '3');
//         output(n - 1, '2', '1', '3');
//     }
// }