#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <set>
#define llong long long

using namespace std;

set<llong> S;
int cnt = 0, n, pos;
llong c[200006], a[200006];
int bit[200006];

void compress() {
    cnt = 0;
    for(set<llong>::iterator i = S.begin(); i != S.end(); ++i) c[++cnt] = *i;
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
    S.clear();
    fast_scan(n), fast_scan(pos);
    for(int i=1; i<=n; ++i) fast_scan(a[i]), S.insert(a[i]);
    compress();
}

void maximize(int &A, int B) {
     if (B > A) A = B;
}

void update(int p, int val) {
    for(; p <= cnt; p += (p & (-p))) maximize(bit[p], val);
}

int  query(int p) {
    int ans = 0;
    for(; p>0; p-=(p & (-p))) maximize(ans, bit[p]);
    return ans;
}

void process() {
    int res = 0, _BAT = 0;
    for(int i=1; i<=cnt; ++i) bit[i] = 0;
    for(int i=1; i<=n; ++i) {
        int u = max(query(a[i]-1), _BAT) + 1;
        if (i == pos) _BAT = u;
        res = max(res, u);
        update(a[i], u);
    }
    cout << res << "\n";
}

int main() {
    int t; fast_scan(t); 
    while(t--) {
       enter();
       process();
    }
}
    
