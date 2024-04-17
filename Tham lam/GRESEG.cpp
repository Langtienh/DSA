#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <set>
#define pii pair<int, int>

using namespace std;

struct Data {
    int x, y, pos;
    
    bool operator > (const Data &other) const {
        return x > other.x || (x == other.x && y < other.y);
    }
} a[600006];

set<int> S;
int cnt = 0, n;
int c[600006];
pii bit[600006];

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
    fast_scan(n);
    for(int i=1; i<=n; ++i) 
        fast_scan(a[i].x), fast_scan(a[i].y), S.insert(a[i].y), a[i].pos = i;
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
    pii ans = make_pair(0, 0);
    for(; p>0; p-=(p & (-p))) maximize(ans, bit[p]);
    return ans;
}

void process() {
    for(int i=1; i<=n; ++i) {
        pii u = query(a[i].y);
        if (u.first > 0) {
            cout << u.second << " " << a[i].pos;
            return;
        }
        u.second = a[i].pos; u.first = 1;
        update(a[i].y, u);
    }
    cout << -1;
}

int main() {
    enter();
    process();
}
    
