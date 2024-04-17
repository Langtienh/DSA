#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[100006], b[100006];
int n, m;
llong k;

llong check(int mid) {
    int l = n - mid + 1;
    llong sum = 0;
    for(int i=1; i<=mid; ++i, ++l)
        if (b[i] > a[l]) sum += b[i] - a[l];
    return sum;
}

int main() {
    scanf("%d%d%I64d", &n, &m, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=m; ++i) scanf("%d", &b[i]);
    sort(a+1, a+n+1); sort(b+1, b+m+1);
    int l = 1, r = min(m, n), ans = 0;
    llong _best = 0;
    while (l <= r) {
        int mid = (l+r) >> 1;
        llong sum = check(mid);
        if (sum <= k) {
            ans = mid;
            _best = sum;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans << " " << _best;
}
    
