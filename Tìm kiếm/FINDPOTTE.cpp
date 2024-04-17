#pragma GCC optimize("O3")
#include <iostream>
#define llong long long

using namespace std;

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

int T, n, m, a[100006], b[100006], Tl_a, Tl_b, Tr_a, Tr_b;

bool check_time_A(int time, llong x) {
    llong sum = 0;
    for(int i=1; i<=n; ++i) sum += time / a[i];
    return sum >= x;
}

bool check_time_B(int time, llong x) {
    llong sum = 0;
    for(int i=1; i<=m; ++i) sum += time / b[i];
    return sum >= x;
}

bool check(llong x) {
    int l = Tl_a, r = Tr_a, time_A = -1, time_B = -1;
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (check_time_A(mid, x)) {
            time_A = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    l = Tl_b, r = Tr_b;
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (check_time_B(mid, x)) {
            time_B = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    if (time_A == -1 || time_B == -1) {
        if (time_A == -1 && time_B != -1) Tr_b = time_B;
        else if (time_A != -1 && time_B == -1) Tr_a = time_A;
        return false;
    }
    if (time_A + time_B <= T) {
        Tl_a = time_A, Tl_b = time_B;
        return true;
    } else {
        Tr_a = time_A, Tr_b = time_B;
        return false;
    }
}

int main() {
    fast_scan(T); Tr_a = Tr_b = T; Tl_a = 0, Tl_b = 0;
    fast_scan(n);
    for(int i=1; i<=n; ++i) fast_scan(a[i]);
    fast_scan(m);
    for(int j=1; j<=m; ++j) fast_scan(b[j]);

    llong l = 0, r = 5e13, ans = 0;
    while (l <= r) {
        llong mid = (l+r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans;

    return 0;
}
    
