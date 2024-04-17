#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[100006], b[100006], n, q;

int main() {
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        --b[y+1];
        ++b[x];
    }
    for(int i=1; i<=n; ++i) b[i] += b[i-1];
    sort(b+1, b+n+1);
    llong res = 0;
    for(int i=1; i<=n; ++i) res += 1LL*a[i]*b[i];
    cout << res;
    return 0;
}
    
