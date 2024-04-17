#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> S;
int cnt = 0, n;
int c[100006], a[100006];
int bit[100006];

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
    for(int i=1; i<=n; ++i)
        fast_scan(a[i]), S.insert(a[i]);
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

int f[100006];

void process() {
    int res = 1;
    for(int i=1; i<=n; ++i) {
        f[i] = query(a[i]-1);
        update(a[i], f[i] + 1);
    }
    for(int i=1; i<=cnt; ++i) bit[i] = 0;
    for(int i=1; i*2<=n; ++i) swap(a[i], a[n-i+1]);
    for(int i=1; i<=n; ++i) {
        int u = query(a[i]-1);
        if (u > 0 && f[n-i+1] > 0) res = max(res, f[n-i+1] + u + 1);
        update(a[i], u + 1);
    }
    cout << res;
}

int main() {
    enter();
    process();
}
    
