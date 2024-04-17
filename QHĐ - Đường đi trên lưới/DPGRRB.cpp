#include <iostream>
#include <algorithm>

using namespace std;

bool avail[1006][1006];
const int base = 1e9+7;
int m, n, f[1006][1006], p;

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
    fast_scan(m), fast_scan(n), fast_scan(p);
    while (p--) {
        int x, y; fast_scan(x), fast_scan(y);
        avail[x][y] = true;
    }
    f[0][1] = 1;
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) {
        if (avail[i][j]) f[i][j] = 0;
        else f[i][j] = (f[i][j] + (f[i-1][j] + f[i][j-1]) % base) % base;
    }
    cout << f[m][n];
    return 0;
}
    
