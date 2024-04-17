#include <iostream>
#include <algorithm>
#include <set>
#define llong long long

using namespace std;

struct Data {
    int a[4];

    bool operator < (const Data &other) const {
        return a[1] < other.a[1] || (a[1] == other.a[1] && a[2] > other.a[2]);
    }
} P[100006];

set<int> S;
int cnt = 0, n, m;
int c[300006];
llong bit[300006];

void compress() {
    cnt = 0;
    for(set<int>::iterator i = S.begin(); i != S.end(); ++i) c[++cnt] = *i;
    for(int i=1; i<=m; ++i) {
        int j = lower_bound(c+1, c+cnt+1, P[i].a[2]) - c;
        P[i].a[2] = j;
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

void init(Data p) {
    P[++m].a[1] = p.a[1];
    P[m].a[2] = p.a[3];
    P[m].a[3] = p.a[2];
    P[++m].a[1] = p.a[2];
    P[m].a[2] = p.a[3];
    P[m].a[3] = p.a[1];
    S.insert(p.a[2]); S.insert(p.a[3]);
}

void maximize(llong &A, llong B) {
     if (B > A) A = B;
}

void update(int p, llong val) {
    for(; p <= cnt; p += (p & (-p))) maximize(bit[p], val);
}

llong  query(int p) {
    llong ans = 0;
    for(; p>0; p-=(p & (-p))) maximize(ans, bit[p]);
    return ans;
}

void process() {
    compress();
    sort(P+1, P+m+1);
    llong res = 0;
    for(int i=1; i <= cnt; ++i) bit[i] = 0;
    for(int i=1; i<=m; ++i) {
        llong u = query(P[i].a[2] - 1) + P[i].a[3];
        res = max(res, u);
        update(P[i].a[2], u);
    }
    cout << res;
    putchar('\n');
}

int main() {
    while (fast_scan(n)) {
        if (n == 0) break;
        m = 0; S.clear();
        for(int i=1; i<=n; ++i) {
            fast_scan(P[++m].a[1]);
            fast_scan(P[m].a[2]);
            fast_scan(P[m].a[3]);
            sort(P[m].a+1, P[m].a+4);
            init(P[m]);
        }
        process();
    }
    return 0;
}
    
