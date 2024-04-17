#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong f[1006][1006];
int m, n, a[1006][1006];
pair<int, int> trace[1006][1006];

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

void print_trace(int x, int y) {
    if (trace[x][y].first != 0 && trace[x][y].second != 0)
        print_trace(trace[x][y].first, trace[x][y].second);
    cout << x << " " << y << "\n";
}

int main() {
    fast_scan(m), fast_scan(n);
    for(int i=2; i<=m; ++i) f[i][0] = -1e18;
    for(int j=1; j<=n; ++j) f[0][j] = -1e18;
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) {
        fast_scan(a[i][j]);
        if (f[i][j-1] > f[i-1][j]) {
            f[i][j] = f[i][j-1] + a[i][j];
            trace[i][j] = make_pair(i, j-1);
        } else {
            f[i][j] = f[i-1][j] + a[i][j];
            trace[i][j] = make_pair(i-1, j);
        }
    }
    cout << f[m][n] << "\n" << m+n-1 << "\n";
    print_trace(m, n);
    return 0;
}
    
