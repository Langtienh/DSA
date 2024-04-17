#include <iostream>
#include <algorithm>
#define fname "BTKTRAU3"
#define llong long long
#define FOR(i, a, b) for(__typeof(a) i = a; i <= b; ++i)

using namespace std;

struct Data {
    llong s;
    int p;

    bool operator < (const Data &other) const {
        return s < other.s || (s == other.s && p < other.p);
    }
} P[100006], P2[100006];

int a[36], x[36];
int n, n1, m1 = 0, m2 = 0;
llong S, w[100006];

void enter() {
    scanf("%d%I64d", &n, &S); n1 = (n >> 1);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
}

void perfect1() {
    llong sum = 0; ++m1;
    FOR(i, 1, n1) sum += x[i]*a[i], P[m1].p += x[i];
    P[m1].s = sum;
}

void perfect2() {
    llong sum = 0; ++m2;
    FOR(i, n1+1, n) sum += x[i]*a[i], P2[m2].p += x[i];
    P2[m2].s = sum;
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

void find_max() {
    llong res = 0;
    int mmin = n+1;
    FOR(i, 1, m2) w[i] = P2[i].s;
    FOR(i, 1, m1) {
        if (P[i].s > S) continue;
        int l = lower_bound(w+1, w+m2+1, S - P[i].s) - w;
        int r = upper_bound(w+1, w+m2+1, S - P[i].s) - w;
        res += r-l;
        if (P2[l].s + P[i].s == S) mmin = min(mmin, P[i].p + P2[l].p);
     }
     if (!res) cout << "KHONG CHON DUOC";
     else cout << res << " " << mmin;
}

int main() {

    enter();
    try1(1);
    try2(n1+1);

    sort(P+1, P+m1+1);
    sort(P2+1, P2+m2+1);
    find_max();

    return 0;
}
    
