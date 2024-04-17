#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong f[2006][2006];
int m, n, a[2006][2006];

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
    for(int j=1; j<=n; ++j) 
        fast_scan(a[i][j]);
    for(int j=1; j<=n; ++j)
    for(int i=1; i<=m; ++i) {
        f[j][i] = f[j-1][i] + a[i][j];
        if (i > 1) f[j][i] = max(f[j][i], f[j-1][i-1]+a[i][j]);
        if (i < m) f[j][i] = max(f[j][i], f[j-1][i+1]+a[i][j]);  
    }
    cout << *max_element(f[n]+1, f[n]+m+1);
    return 0;
}
    
