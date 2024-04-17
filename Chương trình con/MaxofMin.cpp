#pragma GCC optimize("O3")
#include <iostream>

using namespace std;

long long a[1000006];
int n;
int DQ[1000006], l_dq=0, r_dq=0;

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
    fast_scan(n);
    long long res = -1e18;
    for(int i=1; i<=n; ++i) {
         fast_scan(a[i]);
         while (l_dq <= r_dq && DQ[l_dq] <= i-3) ++l_dq;
         while (l_dq <= r_dq && a[DQ[r_dq]] >= a[i]) --r_dq;
         DQ[++r_dq] = i;
         if (i >= 3) res = max(res, a[DQ[l_dq]]);
    }
    cout << res;

    return 0;
}
    
