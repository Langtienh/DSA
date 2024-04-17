#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

using namespace std;

int L[506][506], U[506][506], f[506][506], a[506][506], b[506][506], n, m;

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


void init() {
    for(int j=1; j<=n; ++j)
    for(int i=1; i<=m; ++i) U[i][j] = U[i-1][j] + b[i][j];
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) L[i][j] = L[i][j-1] + a[i][j];
}

void process() {
    int res = 0;
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) {
        f[i][j] = max(f[i][j-1]+U[i][j], f[i-1][j]+L[i][j]);
        res = max(res, f[i][j]);
    }
    cout << res << "\n";
}

int main() {
    fast_scan(m); fast_scan(n);
    while (n != 0) {
        for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) fast_scan(a[i][j]);
        for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) fast_scan(b[i][j]);
        init();
        process();
        fast_scan(m); fast_scan(n);
    }
    return 0;
}
    
