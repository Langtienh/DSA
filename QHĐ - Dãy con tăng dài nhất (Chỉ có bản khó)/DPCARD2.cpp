#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>

using namespace std;

int color[5];

struct Data {
    int x, y, pos;

    bool operator < (const Data &other) const {
        return color[x] < color[other.x] || (color[x] == color[other.x] && y < other.y);
    }
} P[300006];

int bit[300006], c, n;

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

void maximize(int &A, int B) {
     if (B > A) A = B;
}

void update(int p, int val) {
    for(; p <= n; p += (p & (-p))) maximize(bit[p], val);
}

int  query(int p) {
    int ans = 0;
    for(; p>0; p-=(p & (-p))) maximize(ans, bit[p]);
    return ans;
}

int res = 0;

void process() {
    sort(P+1, P+n+1);
    for(int i=1; i<=n; ++i) bit[i] = 0;
    for(int i=1; i<=n; ++i) {
        int u = query(P[i].pos - 1) + 1;
        res = max(res, u);
        update(P[i].pos, u);
    }
}

void _next() {
    int j, k, r, s;
    j = c - 1;
    while (j > 0 && color[j] > color[j + 1]) --j;
    k = c;
    while (color[j] > color[k]) k--;
    swap(color[j], color[k]);
    r = j + 1; s = c;
    while (r < s){
        swap(color[r], color[s]);
        r++;
        s--;
    }
}

int main() {
    fast_scan(c), fast_scan(n); n*=c;
    for(int i=1; i<=n; ++i) {
        fast_scan(P[i].x);
        fast_scan(P[i].y);
        P[i].pos = i;
    }
    int c1 = 1;
    for(int i=1; i<=c; ++i) c1*=i, color[i] = i;
    process();
    for(int i=1; i<c1; ++i) {
        _next();
        process();
    }

    cout << n - res;
    return 0;
}
    
