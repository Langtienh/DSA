#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define llong long long
#define FOR(i, a, b) for(__typeof(a) i = a; i <= b; ++i)
#define sz size();

using namespace std;

struct Data {
    llong val;
    llong weight;

    bool operator < (const Data &other) const {
        return weight < other.weight;
    }
} P[1100006], P2[1100006];

int w[46], v[46], x[46];
int n, n1, n2, m1 = 0, m2 = 0;
llong L, R, w2[1100006], t[4200006], val_max[1100006];
set<llong> W;

void enter() {
    scanf("%d%I64d%I64d", &n, &L, &R); n1 = (n >> 1);
    for(int i=1; i<=n; ++i) scanf("%d%d", &w[i], &v[i]);
}

void perfect1() {
    llong sum_val = 0, sum_weight = 0;
    FOR(i, 1, n1) sum_weight += x[i]*w[i], sum_val += v[i]*x[i];
    P[++m1].val = sum_val;
    P[m1].weight = sum_weight;
}

void perfect2() {
    llong sum_val = 0, sum_weight = 0;
    FOR(i, n1+1, n) sum_weight += x[i]*w[i], sum_val += v[i]*x[i];
    P2[++m2].val = sum_val;
    P2[m2].weight = sum_weight;
    W.insert(sum_weight);
}

void try1(int cnt) {
    if (cnt == n1 + 1) {
        perfect1();
        return;
    }
    FOR(i, 0, 1) x[cnt] = i, try1(cnt+1);
}

void try2(int cnt) {
    if (cnt == n + 1) {
        perfect2();
        return;
    }
    FOR(i, 0, 1) x[cnt] = i, try2(cnt+1);
}

void compress() {
    vector<llong> W1(W.begin(), W.end()); n2 = W1.sz;
    for(int i=1; i<=m2; ++i) {
        int j = lower_bound(W1.begin(), W1.end(), P2[i].weight) - W1.begin();
        w2[++j] = P2[i].weight;
        P2[i].weight = j;
        val_max[P2[i].weight] = max(val_max[P2[i].weight], P2[i].val);
    }
}

void build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
        t[id] = val_max[l];
        return;
    }
    int mid = (l+r)>>1;
    build(id << 1, l, mid);
    build((id << 1) | 1, mid+1, r);
    t[id] = max(t[id << 1], t[(id << 1) | 1]);
}

llong query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return t[id];
    int mid = (l+r) >> 1;
    return max(query(id<<1, l, mid, u, v), query((id<<1) | 1, mid+1, r, u, v));
}

void find_max() {
    llong res = 0;
    FOR(i, 1, m1) {
    	if (P[i].weight > R) continue;
        int l = lower_bound(w2+1, w2+n2+1, L - P[i].weight) - w2;
        int r = upper_bound(w2+1, w2+n2+1, R - P[i].weight) - w2;
        res = max(res, P[i].val + query(1, 1, n2, l, r-1));
     }
     cout << res;
}

int main() {

    enter();
    try1(1);
    try2(n1+1);

    sort(P2+1, P2+m2+1);
    compress();
    build(1, 1, n2);
    find_max();

    return 0;
}
    
