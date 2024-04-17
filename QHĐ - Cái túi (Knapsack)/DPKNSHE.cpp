#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong f[10006];
int n, x[506], y[506];

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
    int t; fast_scan(t);
    while (t--) {
        int l, r;
        fast_scan(l), fast_scan(r), r-=l;
        fast_scan(n);
        for(int i=1; i<=n; ++i)
            fast_scan(y[i]), fast_scan(x[i]);
        for(int i=1; i<=r; ++i) {
            f[i] = 1e18;
            for(int j=1; j<=n; ++j)
                if (x[j] <= i) f[i] = min(f[i], f[i-x[j]] + y[j]);
        }
        if (f[r] == 1e18) cout << "-1\n";
        else cout << f[r] << "\n";
    }
    return 0;
}
    
