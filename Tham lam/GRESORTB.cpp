#include <iostream>
#include <algorithm>
#define pii pair<int, int>
#define mk make_pair

using namespace std;

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

int n, a[200006];
pii T[800006];

pii cmp(pii A, pii B) {
    if (A.second == 0) return B;
    if (B.second == 0) return A;
    if (A.first > B.first) return B;
    else return A;
}

void update(int id, int l, int r, int x, int val) {
    if (l > x || r < x) return;
    if (l == r) {
        T[id].first = x;
        T[id].second += val;
        return;
    }
    int mid = (l+r) >> 1;
    update(id << 1, l, mid, x, val);
    update((id << 1) | 1, mid+1, r, x, val);
    T[id] = cmp(T[id << 1], T[(id << 1) | 1]);
}

pii query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return {0, 0};
    if (u <= l && r <= v) return T[id];
    int mid = (l + r) >> 1;
    return cmp(query(id << 1, l, mid, u, v), query((id << 1) | 1, mid+1, r, u, v));
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1, b; i<=n; ++i) {
        scanf("%d", &b);
        update(1, 1, n, b+1, 1);
    }
    for(int i=1; i<=n; ++i) {
        pii v = query(1, 1, n, (n - a[i]) % n +1, n);
        if (v.second == 0) v = query(1, 1, n, 1, (n - a[i]) % n);
        cout << (v.first + a[i] - 1) % n << " ";
        update(1, 1, n, v.first, -1);
    }
    return 0;
}
    
