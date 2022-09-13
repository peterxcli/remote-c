#include<iostream>
#include<string.h>
#include <sstream>
using namespace std;
int main(){
    stringstream s1;
    s1.str("");
    int f = 0;
    string name_input[3];
    for(int i = 0; i < 3; i++){
        getline(cin, name_input[i]);
    }
    
    for(int i = 0; i < 3; i++){
        int j = 0;
        char a[10];
        s1.clear();
        s1.str(name_input[i]);
        while(!s1.fail()){
            s1 >> a;
            if(strcmp("BILL", a) == 0){
                cout << i + 1 << " " << j + 1;
                f = 1;
                break;
            }
		    j++;
        }
    }
    if(f == 0)
        cout << "NO";
}