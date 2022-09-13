#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;


void _delete(char *peter, int pos);
int main()
{
    static char peter[100] = {'\0'};
    int i = 0;             //[()][] --> 
    while(i < 3){
        cin >> peter;
        int correct = 0, next = 1;
        // cout << strlen(peter) << endl;///////////
        while (next && strlen(peter) >= 2) {
            correct = 0;
            int len = strlen(peter);
            next = 0;
            for(int j = 0; j < len - 1; j++){
                if((peter[j] == '[' && peter[j + 1] == ']') || (peter[j] == '(' && peter[j + 1] == ')')){
                    _delete(peter, j);
                    correct = 1;
                }
            }
            if(correct)
                next = 1;
        }
        if(correct)
            cout << "Correct" << endl;
        else
            cout << "Error" << endl;
        i++;
    }
}

void _delete(char *peter, int pos){
    int len = strlen(peter);
    for(int i = pos; i < len; i += 2){// ewrwer  er --> ewrwerer
        char temp1 = peter[i + 2];
        char temp2 = peter[i + 3];
        peter[i] = temp1;
        peter[i + 1] = temp2; 
    }
    peter[len - 2] = '\0';
    peter[len - 1] = '\0';
}
