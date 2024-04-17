#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Data {
    int x, y;

    bool operator < (const Data &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
} a[100006];

set<int> S;
int cnt = 0, n;
int c[200006];
int bit[200006];

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
        fast_scan(a[i].x), fast_scan(a[i].y), S.insert(a[i].y);
    compress();
    sort(a+1, a+n+1);
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
    int res = 0, pos = 0;
    for(int i=1; i<=n; ++i) {
        int u = query(a[i].y) + 1;
        if (res < u) res = u;
        update(a[i].y, u);
    }
    cout << n - res;
}

int main() {
    enter();
    process();
}
    
