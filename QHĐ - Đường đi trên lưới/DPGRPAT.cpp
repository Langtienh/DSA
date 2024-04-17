#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
bool fast_scan(T &num) {
    num = 0;
    register char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return false;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    return true;
}

const int base = 1e9;
int f[106][106], a[106][106], m, n;

int main() {
    fast_scan(m), fast_scan(n);
    for(int i=1; i<=m; ++i) {
        f[1][i] = 1;
        for(int j=1; j<=n; ++j) fast_scan(a[i][j]);
    }
    for(int j=1; j<=n; ++j)
    for(int i=1; i<=m; ++i)
    for(int l=1; l<=min(j, n-1); ++l)
    for(int k=1; k<=i; ++k)
        if (i+j>k+l && __gcd(a[i][j], a[k][l])>1) f[j][i] += f[l][k], f[j][i] %= base;
    int res = 0;
    for(int i=1; i<=m; ++i) res += f[n][i], res %= base;
    cout << res;
    return 0;
}
    
