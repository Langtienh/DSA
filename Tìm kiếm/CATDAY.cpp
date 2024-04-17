#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[100006], n;
llong k;

bool check(int mid) {
    llong sum = 0;
    for(int i=1; i<=n; ++i) sum += a[i] / mid;
    return sum >= k; 
}

int main() {
    scanf("%d%I64d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    int l = 1, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans;
    
    return 0;
}
    
