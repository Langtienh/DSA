#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int L, N, p[506], dp[206][206][506], C[206][206];

int get_res(int v1, int v2, int pos) {
    if (pos > N) return 0;
    int v3 = p[pos-1];
    if (dp[v1][v2][pos] != -1) return dp[v1][v2][pos];
    if (v3 == p[pos]) return dp[v1][v2][pos] = get_res(v1, v2, pos+1);
    if (v2 == p[pos]) return dp[v1][v2][pos] = get_res(v1, v3, pos+1);
    if (v1 == p[pos]) return dp[v1][v2][pos] = get_res(v2, v3, pos+1);
    int tmp = min(get_res(v2, v3, pos+1) + C[v1][p[pos]], get_res(v1, v3, pos+1) + C[v2][p[pos]]);
    return dp[v1][v2][pos] = min(tmp, get_res(v1, v2, pos+1) + C[v3][p[pos]]);
}

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
        fast_scan(L), fast_scan(N);
        for(int i=1; i<=L; ++i)
        for(int j=1; j<=L; ++j) fast_scan(C[i][j]);
        for(int i=1; i<=N; ++i) fast_scan(p[i]);
        p[0] = 3;
        for(int i=1; i<=L; ++i)
        for(int j=1; j<=L; ++j)
        for(int k=1; k<=N; ++k) dp[i][j][k] = -1;
        cout << get_res(1, 2, 1) << "\n";
    }
    return 0;
}
    
