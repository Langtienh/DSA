#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> S;
int cnt = 0, n, pos;
int c[200006], a[200006];
int bit[200006];
bool avail[200006];

void compress() {
    cnt = 0;
    for(set<int>::iterator i = S.begin(); i != S.end(); ++i) c[++cnt] = *i;
    for(int i=1; i<=n; ++i) {
        int j = lower_bound(c+1, c+cnt+1, a[i]) - c;
        a[i] = cnt - j + 1;
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
    fast_scan(n);
    for(int i=1; i<=n; ++i) fast_scan(a[i]), S.insert(a[i]);
    compress();
}

void update(int p, int val) {
    for(; p <= cnt; p += (p & (-p))) bit[p] = max(bit[p], val);
}

int  query(int p) {
    int ans = 0;
    for(; p>0; p-=(p & (-p))) ans = max(ans, bit[p]);
    return ans;
}

int f[200006];

void process() {
    int res = 0;
    for(int i=n; i; --i) {
        f[i] = query(a[i]-1) + 1;
        update(a[i], f[i]);
    }
    for(int i=1; i<=cnt; ++i) bit[i] = 0;
    for(int i=1; i<=n; ++i) {
        int u = max(query(a[i] - 1) + 1, f[i]);
        res = max(res, u);
        update(a[i], u);
    }
    cout << res;
}

int main() {
    enter();
    process();
}
    
