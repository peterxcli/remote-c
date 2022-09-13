#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    vector<ll> seq;

    ll temp, sum = 0, N;

    cin >> N;

    while(N-- && cin >> temp)
        seq.push_back(temp);

    sort(seq.begin(), seq.end());
    
    for(ll i = 1; i < seq.size(); i++) 
        seq[i] += seq[i-1]; 
    
    for(ll i = 0; i < seq.size()-1; i++)
        sum += seq[i];
    cout << sum*100 << endl;
}