#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int m, a[1000006], n;

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

bool check(llong mid) {
    int sum = 0;
    llong p = mid;
    for(int i=1; i<=n; ++i)
        if (p >= a[i]) p-= a[i]; else ++sum, p = mid - a[i];
    ++sum;
    return sum <= m;
}

int main() {
    fast_scan(n), fast_scan(m);
    llong l = 0;
    for(int i=1; i<=n; ++i) fast_scan(a[i]), l = max(l, 1LL*a[i]);
    llong r = 1e16, ans = 0;
    while (l <= r) {
        llong mid = (l+r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans;

    return 0;
}
    
