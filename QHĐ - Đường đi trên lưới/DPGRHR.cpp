#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[506][506], f[506][506], n, m;
bool avail[506][506];

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

bool check(llong s) {
    f[1][1] = s; 
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) {
        avail[i][j] = false; 
        if (i == 1 && j == 1) continue;
        f[i][j] = 0;
        avail[i][j] = avail[i-1][j] && avail[i][j-1];
        if (avail[i][j]) continue;
        int tmp = max(f[i][j-1], f[i-1][j]);
        tmp += a[i][j];
        if (tmp <= 0) avail[i][j] = true;
        if (avail[i][j]) continue;
        f[i][j] = tmp;
    }
    return (!avail[m][n]) && f[m][n] > 0;
}

llong b_search() {
    for(int i=1; i<=m; ++i) avail[i][0] = avail[i][n] = true;
    for(int i=1; i<=n; ++i) avail[0][i] = avail[m][i] = true;
    llong l = 1, r = 1e9, ans = 0;
    while (l <= r) {
        llong mid = (l+r)>>1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int main() {
    int p; fast_scan(p);
    while (p--) {
        fast_scan(m), fast_scan(n);
        for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) fast_scan(a[i][j]);
        cout << b_search() << "\n";
    }
    return 0;
}
    
