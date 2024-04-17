#include <iostream>
#include <algorithm>
#define fname "BTKTRAU5"
#define llong long long
#define FOR(i, a, b) for(__typeof(a) i = a; i <= b; ++i)

using namespace std;

struct Data {
    llong W;
    llong s;

    bool operator < (const Data &other) const {
        return s < other.s || (s == other.s && W > other.W);
    }
} P[200006], P2[200006];

llong w[200006];
int a[43], x[43];
int n, n1, m1 = 0, m2 = 0;

void enter() {
    scanf("%d", &n); n1 = (n >> 1);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
}

void perfect1() {
    llong sum = 0, sum1 = 0;
    FOR(i, 1, n1)
        if (x[i] == 0) sum += a[i];
        else if (x[i] == 1) sum1 += a[i];
    P[++m1].s = sum1 - sum;
    P[m1].W = sum;
}

void perfect2() {
    llong sum = 0, sum1 = 0;
    FOR(i, n1+1, n)
        if (x[i] == 0) sum += a[i];
        else if (x[i] == 1) sum1 += a[i];
    P2[++m2].s = sum1 - sum;
    P2[m2].W = sum;
}

void try1(int cnt) {
    if (cnt == n1 + 1) {
        perfect1();
        return;
    }
    FOR(i, 0, 2) x[cnt] = i, try1(cnt+1);
}

void try2(int cnt) {
    if (cnt == n + 1) {
        perfect2();
        return;
    }
    FOR(i, 0, 2) x[cnt] = i, try2(cnt+1);
}

void find_max() {
    llong res = 0;
    FOR(i, 1, m2) w[i] = P2[i].s;
    FOR(i, 1, m1) {
        int j = lower_bound(w+1, w+m2+1, -P[i].s) - w;
        if (P2[j].s + P[i].s == 0) res = max(res, abs(P2[j].W + P[i].W));
     }
     cout << res;
}

int main() {

    enter();
    try1(1);
    try2(n1+1);

    sort(P2+1, P2+m2+1);
    find_max();

    return 0;
}
    
