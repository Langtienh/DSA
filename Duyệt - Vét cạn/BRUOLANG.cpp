#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    int kind, x, y;
    llong w;
} b[100006];

llong a[100006], S[100006], c[100006], d[100006];
int n, m, k;

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
    fast_scan(n), fast_scan(m), fast_scan(k);
    for(int i=1; i<=n; ++i) fast_scan(a[i]);
    for(int i=1; i<=m; ++i) {
        fast_scan(b[i].kind), fast_scan(b[i].x), fast_scan(b[i].y), fast_scan(b[i].w);
        if (b[i].kind == 2) b[i].w *= (-1);
    }
    for(int i=1; i<=k; ++i) {
        int kind, x, y; fast_scan(kind), fast_scan(x), fast_scan(y);
        ++c[x], --c[y+1];
    }
    for(int i=1; i<=m; ++i) {
        c[i] += c[i-1];
        d[b[i].x] += c[i] * b[i].w, d[b[i].y+1] -= c[i] * b[i].w;
    }
    for(int i=1; i<=n; ++i) {
        d[i] += d[i-1];
        a[i] += d[i];
        S[i] = S[i-1] + a[i];
    }
    int u1, v1, u2, v2;
    llong S1, S2;
    fast_scan(u1), fast_scan(v1), fast_scan(S1);
    fast_scan(u2), fast_scan(v2), fast_scan(S2);
    if (abs(S[v1] - S[u1-1] - S1) < abs(S[v2] - S[u2-1] - S2)) cout << "SAN WIN";
    else if (abs(S[v1] - S[u1-1] - S1) > abs(S[v2] - S[u2-1] - S2)) cout << "MI WIN";
    else cout << "HOA";
    return 0;
}
    
