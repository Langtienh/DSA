#include <iostream>
#include <algorithm>

using namespace std;

int f[105][105][105], a[105][105];

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

int m, n, res = 0;

int main() {
    fast_scan(m), fast_scan(n);
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) fast_scan(a[i][j]);
        for(int j=1; j<=n; ++j)
        for(int k=1; k<=n; ++k) {
            int add;
            if (j == k) add = a[i][j];
            else add = a[i][j] + a[i][k];
            for(int u=j-1; u<=j+1; ++u)
            for(int v=k-1; v<=k+1; ++v) f[i][j][k] = max(f[i][j][k], f[i-1][u][v] + add);
            if (i == m) res = max(res, f[i][j][k]);
        }
    }
    cout << res;
    return 0;
}
    
