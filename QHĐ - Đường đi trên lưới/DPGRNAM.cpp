#include <iostream>

using namespace std;

const int base = 1e7;
int f[506][506][8], n, m;

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
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) {
        int a; fast_scan(a);
        if (a == -1) continue;
        if (a == 0 && i == 1 && j == 1) f[1][1][0] = 1;
        else if (a != 0) {
            a = (1 << (a-1));
            for(int k=0; k<8; ++k) f[i][j][a | k] = (f[i][j][a | k] + f[i-1][j][k] + f[i][j-1][k]) % base;
        } else for(int k=0; k<8; ++k) f[i][j][k] = (f[i][j][k] + f[i-1][j][k] + f[i][j-1][k]) % base;
    }
    cout << (f[m][n][3] + f[m][n][5] + f[m][n][6] + f[m][n][7]) % base;
    return 0;
}
    
