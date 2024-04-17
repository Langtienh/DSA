#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <set>
#define pii pair<int, int>
#define mk make_pair

using namespace std;

struct Data {
    int x, y, pos;

    bool operator > (const Data &other) const {
        return x > other.x || (x == other.x && y < other.y);
    }
} a[100006];

set<int> S;
int cnt = 0, n;
int c[200006];
pii bit[200006];

void compress() {
    for(set<int>::iterator i = S.begin(); i != S.end(); ++i) c[++cnt] = *i;
    for(int i=1; i<=n; ++i) {
        int j = lower_bound(c+1, c+cnt+1, a[i].y) - c;
        a[i].y = j;
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
    n = 1; fast_scan(a[1].x);
    while (a[n].x != 0) {
        fast_scan(a[n].y), S.insert(a[n].y);
        a[n].pos = n;
        fast_scan(a[++n].x);
    } --n;
    compress();
    sort(a+1, a+n+1, greater<Data>());
}

void maximize(pii &A, pii B) {
     if (B.first > A.first) A = B;
}

void update(int p, pii val) {
    for(; p <= cnt; p += (p & (-p))) maximize(bit[p], val);
}

pii  query(int p) {
    pii ans = mk(0, 0);
    for(; p>0; p-=(p & (-p))) maximize(ans, bit[p]);
    return ans;
}

int trace[100006];
int V[100006], num = 0;

void process() {
    int res = 0, pos = 0;
    for(int i=1; i<=n; ++i) {
        pii u = query(a[i].y); ++u.first;
        trace[a[i].pos] = u.second;
        if (res < u.first) {
           res = u.first;
           pos = a[i].pos;
        }
        u.second = a[i].pos;
        update(a[i].y, u);
    }
    cout << res; putchar('\n');
    while (pos != 0) {
        V[++num] = pos;
        pos = trace[pos];
    }
    for(int i=1; i<=num; ++i) cout << V[i] << " ";
}

int main() {
    enter();
    process();
}
    
