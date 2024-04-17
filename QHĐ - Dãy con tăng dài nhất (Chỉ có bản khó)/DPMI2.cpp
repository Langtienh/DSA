#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <set>
#define pii pair<int, int>

using namespace std;

struct Data {
    int x, y;

    bool operator < (const Data &other) const {
        return x < other.x;
    }
} a[100006];

set<int> S;
const int base = 1e8;
int cnt = 0, n;
int c[200006];
pii bit[200006];

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
    for(int i=1; i<=n; ++i) {
        fast_scan(a[i].x), fast_scan(a[i].y), S.insert(a[i].y), S.insert(a[i].x);
        if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
    }
    compress();
    sort(a+1, a+n+1);
}

void operator += (pii &A, pii B) {
     A.first += B.first;
     A.second += B.second;
     A.first %= base;
     A.second %= base;
}

void update(int p, pii val) {
    for(; p <= cnt; p += (p & (-p))) bit[p] += val;
}

pii  query(int p) {
    pii ans = make_pair(0, 0);
    for(; p>0; p-=(p & (-p))) ans += bit[p];
    return ans;
}

void process() {
    int res = 0;
    for(int i=1; i<=cnt; ++i) bit[i] = make_pair(0, 0);
    for(int i=1; i<=n; ++i) {
        pii u = query(a[i].x);
        u.first += u.second; u.first %= base;
        res += u.first + 1; res %= base;
        u.second = 1;
        update(a[i].y, u);
    }
    int res1 = res, len = 0;
    if (res == 0) len = 1;
    while (res1 > 0) ++len, res1/=10;
    for(int i=1; i<=8-len; ++i) cout << 0;
    cout << res; putchar('\n');
}

int main() {
    while (fast_scan(n)) {
        if(n==-1) return 0;
    	enter();
    	process();
    }
}
    
