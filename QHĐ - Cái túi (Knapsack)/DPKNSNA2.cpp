#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong f[2][2000006];
int n, m, S[2000006], n_stack = 0, x, y;

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

int main() {
    fast_scan(m); fast_scan(n);
    int ok = 0;
    llong res = 0;
    fast_scan(y); fast_scan(x);
    for(int i=0; i * x <= m; ++i) f[1][i*x] = 1LL*i*y;
    for(int i=2; i<=n; ++i) {
        fast_scan(y); fast_scan(x);
        if (x > m) continue;
        for(int j=0; j<x; ++j) {
            for(int k = j; k <= m; k += x) {
                while (n_stack && f[1 - ok][S[n_stack]] + 1LL*(k - S[n_stack]) / x * y <= f[1 - ok][k]) --n_stack;
    		S[++n_stack] = k;
                f[ok][k] = f[1 - ok][S[1]] + 1LL*(k - S[1]) / x * y;
                res = max(res, f[ok][k]);
            }
            n_stack = 0;
        }
        ok = 1 - ok;
    }
    cout << res;
    return 0;
}
    
