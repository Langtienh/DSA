#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong f[1006][1006];
int m, n, a[1006][1006];

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
    fast_scan(m), fast_scan(n);
    llong mmax= 0;
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) {
        fast_scan(a[i][j]);
        f[i][j] = max(max(f[i-1][j-1], f[i-1][j]), f[i-1][j+1]) + a[i][j];
    }
    cout << *max_element(f[m]+1, f[m]+n+1);
    return 0;
}
    
