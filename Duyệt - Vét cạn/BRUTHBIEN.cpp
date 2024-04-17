#include <iostream>
#include <algorithm>
#include <set>
#define llong long long

using namespace std;

struct Data {
    int c;
    llong a;
} P[100006];

set<llong> A;
int n, m;
llong c[100006], bit[100006];

void update(int p, llong val) {
    for(; p <= m; p += (p & (-p))) bit[p] = min(bit[p], val);
}

llong query(int p) {
    llong ans = 1e18;
    for(; p > 0; p -= (p & (-p))) ans = min(ans, bit[p]);
    if (ans == 1e18) ans = 0;
    return ans;
}

void compress() {
    vector<llong> S(A.begin(), A.end()); m = S.size();
    if (m < 3) {
        cout << -1;
        exit(0);
    }
    for(int i=1; i<=n; ++i) {
        int j = lower_bound(S.begin(), S.end(), P[i].a) - S.begin();
        P[i].a = ++j;
    }
}

bool avail[100006];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%I64d", &P[i].a);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &P[i].c);
        A.insert(P[i].a);
    }
    compress();
    llong res = 1e18;
    for(int j=1; j<=3; ++j) {
        for(int i=1; i<=m; ++i) bit[i] = 1e18;
        for(int i=1; i<=n; ++i) {
            llong tmp = query(P[i].a-1) + P[i].c;
            if (tmp == P[i].c && j == 2) avail[P[i].a] = true;
            if (P[i].a >= 3 && j == 3 && tmp > P[i].c) res = min(res, tmp);
            if (j <=2 || !avail[P[i].a]) update(P[i].a, c[i]);
            c[i] = tmp;
        }
    }
    if (res == 1e18) res = -1;
    cout << res;

    return 0;
}
    
