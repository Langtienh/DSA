#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[2006][2006];
int v[2006], n;
bool avail[2006][2006];

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

llong get_res(int cnt, int L) {
    if (avail[cnt][L]) return dp[cnt][L];
    avail[cnt][L] = true;
    if (cnt == 1) return dp[cnt][L] = 1LL * v[L] * (1LL*n-cnt+1);
    return dp[cnt][L] = max(get_res(cnt-1, L)+1LL*v[L+cnt-1]*(1LL*n-cnt+1), get_res(cnt-1, L+1)+1LL*v[L]*(1LL*n-cnt+1));
}

int main() {
    fast_scan(n);
    for(int i=1; i<=n; ++i) fast_scan(v[i]);
    cout << get_res(n, 1);
    return 0;
}
    
