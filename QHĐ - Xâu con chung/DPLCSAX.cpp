#include <iostream>
#include <algorithm>
#define ullong unsigned long long

using namespace std;

template<typename T>
int fast_scan(T &num) {
    num = 0;
    register char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return 1;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    return 0;
}

int a[2006], b[2006], block, best;
int n=0, m=0;
ullong f[2006][41], l[2006];

void find_max() {
    for(int i=1; i<=m; ++i) {
        ullong b1 = 1, b2 = 0;
        for(int j=1; j<=block; ++j) {
            ullong u = l[j] | f[b[i]][j];
            ullong v = u - ((l[j] << 1) | (b1+b2));
            b1 = (l[j] >> 63); b2 = (v > u);
            l[j] = u & (~v);
        }
    }
    int res = 0;
    for(int i=1; i<=block; ++i)
        for(; l[i]; ++res) l[i] &= (l[i] - 1);
    best = max(res, best);
}

void init() {
    block = (n + 63) >> 6;
    ullong s = 1; int j = 1;
    for(int i=0; i<=2000; ++i)
    for(int j=0; j<=block; ++j) f[i][j] = 0;
    for(int i=1; i<=n; ++i) {
        f[a[i]][j] |= s;
        s <<= 1;
        if (!s) ++s, ++j;
    }
    best = 0;
}

void process() {
    int A; fast_scan(A); n = 0;
    while (A != 0) {
        a[++n] = A;
        fast_scan(A);
    }
    init();
    int B; fast_scan(B);
    while (B != 0) {
        m = 0;
        while (B != 0) {
            b[++m] = B;
            fast_scan(B);
        }
        find_max();
        fast_scan(B);
    }
    cout << best << "\n";
}

int main() {
    int t; fast_scan(t);
    while (t--) process();
    return 0;
}
    
