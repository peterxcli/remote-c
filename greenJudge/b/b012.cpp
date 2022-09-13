#include<iostream>
#include<string.h>
using namespace std;
int roma_to_num(char roma[]);
int search_index_in_map(char target);
char map_char[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'}; 
int trans[] = {1, 5, 10, 50, 100, 500, 1000};
int numlize[100];


main(){
    char R1[100];
    cin >> R1;
    cout << roma_to_num(R1);
}
int roma_to_num(char roma[]){
    for(int i = 0; i < strlen(roma); i++){
        int index = search_index_in_map(roma[i]);
        numlize[i] = trans[index];
    }
    int sum = 0;
    for(int i = 0;i < strlen(roma); i++)
		sum += numlize[i];
	for(int i = 1; i < strlen(roma); i++)
		if(numlize[i] > numlize[i-1])
			sum -= numlize[i - 1] * 2;
    return sum;
}
int search_index_in_map(char target){
    int index;
    for(int i = 0; i < 7; i++){
        if(target == map_char[i]){
            index = i;
            break;
        }
    }
    return index;
    
}















































































































































































































////////////////////////////////////////////////////////////////////////////////////////////////////fuck 