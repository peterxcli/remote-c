#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void On2();
void Onlogn();

int main() {
    // On2();
    Onlogn();
}

void Onlogn() {
    priority_queue<int, vector<int>, greater<int> > pq;
    int N, temp;
    cin >> N;
    while(N-- && cin >> temp) pq.push(temp);

    int ans = 0;
    while(pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        ans += first + second;
        pq.push(first + second);
    } 
    cout << ans << endl;
}


void On2() {
    vector<int> seq;
    int temp, sum = 0, N;
    cin >> N;
    while(N-- && cin >> temp)
        seq.push_back(temp);

    while(seq.size() > 1) {
        sort(seq.begin(), seq.end());
        // for(int j = 0; j < seq.size(); j++) cout << seq[j] << " "; cout << sum << endl;
        sum += seq[0]+seq[1];
        seq[1] += seq[0];
        seq.erase(seq.begin());
    }
    cout << sum << endl;
}