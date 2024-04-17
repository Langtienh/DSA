#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define pii pair<int, int>
#define mk make_pair

using namespace std;

vector<int> bit[100006], nodes[100006];
set<int> A, B;
int n, r, c, a[100006], b[100006];

void compress() {
    vector<int> A1(A.begin(), A.end()); r = A1.size();
    vector<int> B1(B.begin(), B.end()); c = B1.size();
    for(int i=1, j; i<=n; ++i) {
        j = lower_bound(A1.begin(), A1.end(), a[i]) - A1.begin();
        a[i] = ++j;
        j = lower_bound(B1.begin(), B1.end(), b[i]) - B1.begin();
        b[i] = ++j;
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

void update(int x, int y, int val) {
    for(; x <= r; x += (x & (-x))) {
        int j = lower_bound(nodes[x].begin(), nodes[x].end(), y) - nodes[x].begin() + 1;
        for(; j <= (int) nodes[x].size(); j += (j & (-j)))
            bit[x][j] = max(bit[x][j], val);
    }
}

int query(int x, int y) {
    int ans = 0;
    for(; x > 0; x -= (x & (-x))) {
        int j = upper_bound(nodes[x].begin(), nodes[x].end(), y) - nodes[x].begin();
        for(; j > 0; j -= (j & (-j))) ans = max(bit[x][j], ans);
    }
    return ans;
}

void fakeUpdate(int x, int y) {
    for(; x <= r; x += (x & (-x))) nodes[x].push_back(y);
}

void fakeGet(int x, int y) {
    for(; x > 0; x -= (x & (-x))) nodes[x].push_back(y);
}

void init() {
    for(int i=1; i<=n; ++i) {
        fakeUpdate(a[i], b[i]);
        fakeGet(a[i], b[i]);
    }
    for(int i=1; i<=r; ++i) {
        nodes[i].push_back((int) 1e9);
        sort(nodes[i].begin(), nodes[i].end());
        nodes[i].resize(unique(nodes[i].begin(), nodes[i].end())-nodes[i].begin());
        bit[i].assign(nodes[i].size()+2, 0);
    }
}

int main() {
    fast_scan(n);
    for(int i=1; i<=n; ++i) fast_scan(a[i]), fast_scan(b[i]), A.insert(a[i]), B.insert(b[i]);
    compress();
    init();
    int res = 0;
    for(int i=1; i<=n; ++i) {
        int best = query(a[i]-1, b[i]-1) + 1;
        res = max(res, best);
        update(a[i], b[i], best);
    }
    cout << res;

    return 0;
}
    
