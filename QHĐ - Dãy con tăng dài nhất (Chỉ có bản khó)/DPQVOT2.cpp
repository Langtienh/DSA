#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[100006], n, k, pre[100006];
llong f[100006];

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
    fast_scan(n), fast_scan(k); f[0] = 0, pre[0] = 0;
    for (int i=1, l = 1; i<=n; ++i) {
        fast_scan(a[i]);
        while (a[i] - a[l] >= k) ++l;
        pre[i] = l - 1;
    } 
    for(int i=1, b; i<=n; ++i) {
        fast_scan(b);
        f[i] = max(f[i-1], f[pre[i]] + b);
    }
    cout << f[n];
    
    return 0;
}
    
