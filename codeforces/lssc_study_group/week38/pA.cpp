#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, q, money;
    scanf("%d", &n);

    vector<int> price(n, 0);

    for(int i = 0; i < n; i++) 
        scanf("%d", &price[i]);

    std::sort(price.begin(), price.end());

    scanf("%d", &q);

    for(int i = 0; i < q; i++) {
        scanf("%d", &money);
        int cnt = 0;
        int l = 0, r = n-1;
        while(l < r) {
            int mid = (l+r)/2;
            if(price[mid] > money) r = mid;
            else l = mid+1;
        }
        if(l == n-1 && price[l] <= money) printf("%d\n", l+1); 
        else printf("%d\n", l); 
    }
}
