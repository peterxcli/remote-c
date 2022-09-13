
#include <sstream>
#include <iostream>
using namespace std;
int main()
{
    string s;
    stringstream s1;
    int N, max = 0, max_i = 0;
    int i1;
    cin.ignore();
    string line;
    for(int i = 0;i < 3;i ++){
        getline(cin, line);
        int sum = 0;
        s1.clear();
        s1.str(line);
        while(true){
            s1 >> i1;
            if(s1.fail()) break;
            sum += i1;
        }
        if(sum > max){
            max = sum;
            max_i = i;
        }
      }
    if(max == 1)
        cout << max_i + 1 << " " << max + 1;
    else
        cout << max_i + 1 << " " << max;
}