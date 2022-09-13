#include<iostream>
using namespace std;

struct Student{
    int num;
    int sum ;
    int math;
};
int main(){
    Student student[50];
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> student[i].num;
        int grade_sum = 0;
        for(int j = 0; j < 5; j++){
            int temp;
            cin >> temp;
            grade_sum += temp;
            if(j == 2) student[i].math = temp;
        }
        student[i].sum = grade_sum;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(student[j].sum < student[j + 1].sum){
                Student temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(student[j].sum == student[j + 1].sum){
                if(student[j].math < student[j + 1].math){
                    Student temp = student[j];
                    student[j] = student[j + 1];
                    student[j + 1] = temp;
                }
            }
        }
    }
    for(int i = 0; i < N; i++)
        cout << student[i].num << endl;
}
