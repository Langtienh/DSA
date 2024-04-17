#include <iostream>
#include <algorithm>
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

int n, m, k, p[6006];
llong S[6006], dp[6006][6006];
bool avail[6006][6006];

llong get_res(int cnt, int pos) {
    if (avail[cnt][pos]) return dp[cnt][pos];
    avail[cnt][pos] = true;
    if (cnt == 1) return dp[cnt][pos] = S[pos] - S[pos-m];
    for(int i=pos+m; i<=n-(cnt-2)*m; ++i)
        dp[cnt][pos] = max(dp[cnt][pos], get_res(cnt-1, i)+S[pos] - S[pos-m]);
    return dp[cnt][pos];
}

int main() {
    fast_scan(n), fast_scan(m), fast_scan(k);
    for(int i=1; i<=n; ++i) fast_scan(p[i]), S[i] = S[i-1] + p[i];
    llong res = 0;
    for(int i=m; i<=n-(k-1)*m; ++i) res = max(res, get_res(k, i));
    cout << res;
    return 0;
}
    
