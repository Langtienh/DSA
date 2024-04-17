#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <set>
#define llong long long
#define pii pair<llong, int>
#define mk make_pair


using namespace std;

set<int> S;
int cnt = 0, n;
int c[200006], a[200006];
pii bit[200006];

void compress() {
    for(set<int>::iterator i = S.begin(); i != S.end(); ++i) c[++cnt] = *i;
    for(int i=1; i<=n; ++i) {
        int j = lower_bound(c+1, c+cnt+1, a[i]) - c;
        a[i] = j;
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

void maximize(pii &A, pii B) {
     if (B.first > A.first) A = B;
}

void update(int p, pii val) {
    for(; p <= cnt; p += (p & (-p))) maximize(bit[p], val);
}

pii  query(int p) {
    pii ans = mk(0LL, 0);
    for(; p>0; p-=(p & (-p))) maximize(ans, bit[p]);
    return ans;
}

int trace[200006];

void process() {
    llong res = 0;
    int pos = 0;
    for(int i=1; i<=n; ++i) {
        pii u = query(a[i]);
        u.first += c[a[i]]; trace[i] = u.second;
        if (res < u.first) {
            res = u.first;
            pos = i;
        }
        u.second = i;
        update(a[i], u);
    }
    cout << res;
}

int main() {
    enter();
    process();
}
    
