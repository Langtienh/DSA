#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <set>
#define llong long long

using namespace std;

struct Data {
    int x, y, val;

    bool operator < (const Data &other) const {
        return x < other.x;
    }
} a[100006];

set<int> S;
int cnt = 0, n;
int c[200006];
llong bit[200006];

void compress() {
    cnt = 0;
    for(set<int>::iterator i = S.begin(); i != S.end(); ++i) c[++cnt] = *i;
    for(int i=1; i<=n; ++i) {
        int j = lower_bound(c+1, c+cnt+1, a[i].y) - c;
        a[i].y = j;
        j = lower_bound(c+1, c+cnt+1, a[i].x) - c;
        a[i].x = j;
    }
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

void enter() {
    S.clear();
    fast_scan(n);
    for(int i=1; i<=n; ++i) {
        fast_scan(a[i].x), fast_scan(a[i].y);
        a[i].y += a[i].x - 1, S.insert(a[i].y), S.insert(a[i].x);
        fast_scan(a[i].val);
    }
    compress();
    sort(a+1, a+n+1);
}

void maximize(llong &A, llong B) {
     if (B > A) A = B;
}

void update(int p, llong val) {
    for(; p <= cnt; p += (p & (-p))) maximize(bit[p], val);
}

llong query(int p) {
    llong ans = 0;
    for(; p>0; p-=(p & (-p))) maximize(ans, bit[p]);
    return ans;
}

void process() {
    llong res = 0;
    for(int i=1; i<=cnt; ++i) bit[i] = 0;
    for(int i=1; i<=n; ++i) {
        llong u = query(a[i].x-1) + a[i].val;
        if (res < u) res = u;
        update(a[i].y, u);
    }
    cout << res; putchar('\n');
}

int main() {
    int t = 0; fast_scan(t);
    while (t--) {
       enter();
       process();
    }
}
    
