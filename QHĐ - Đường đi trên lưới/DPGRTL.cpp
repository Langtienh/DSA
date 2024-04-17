#include <iostream>
#include <algorithm>

using namespace std;

int f[1006][1006], m, n, a, b;

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
    fast_scan(a), fast_scan(b);
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) {
        fast_scan(f[i][j]);
        if (i >= a && j >= b && i+j>a+b) {
            if (i == a) f[i][j] = f[i][j-1] - f[i][j];
            else if (j == b) f[i][j] = f[i-1][j] - f[i][j];
            else f[i][j] = max(f[i][j-1], f[i-1][j]) - f[i][j];
        }
    }
    if (f[m][n] >= 0) cout << "Y " << f[m][n];
    else cout << "N";
    return 0;
}
    
