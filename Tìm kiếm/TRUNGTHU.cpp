#include <iostream>
#include <algorithm>

using namespace std;

int n, x, a[100006];

int main() {
    scanf("%d%d", &n, &x);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int l = 1, r = n, res = 0;
    while (l < r) {
        while (l < r && a[l] + a[r] > x) --r;
        if (l == r) break;
        res = max(res, a[l] + a[r]);
        ++l;
    }
    cout << res;
    return 0;
}
    
