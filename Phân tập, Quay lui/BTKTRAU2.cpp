#include <iostream>
#include <algorithm>
#define fname "BTKTRAU2"
#define llong long long
#define FOR(i, a, b) for(__typeof(a) i = a; i <= b; ++i)

using namespace std;

struct Data {
    llong s;
    int p[36];

    bool operator < (const Data &other) const {
        return s < other.s;
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
    FOR(i, 1, n1) sum += x[i]*a[i], P[m1].p[i] = x[i];
    P[m1].s = sum;
}

void perfect2() {
    llong sum = 0; ++m2;
    FOR(i, n1+1, n) sum += x[i]*a[i], P2[m2].p[i] = x[i];
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
    FOR(i, 1, m2) w[i] = P2[i].s;
    FOR(i, 1, m1) {
        if (P[i].s > S) continue;
        int j = lower_bound(w+1, w+m2+1, S - P[i].s) - w;
        if (j <= m2 && P2[j].s + P[i].s == S) {
            cout << "YES\n";
            static int cnt = 0, trace[36];
            FOR(k, 1, n1)
                if (P[i].p[k] == 1) trace[++cnt] = k;
            FOR(k, n1+1, n)
                if (P2[j].p[k] == 1) trace[++cnt] = k;
            cout << cnt << "\n";
            FOR(k, 1, cnt) cout << trace[k] << " ";
            return;
        }
     }
     cout << "NO";
}

int main() {

    enter();
    try1(1);
    try2(n1+1);

    sort(P2+1, P2+m2+1);
    find_max();

    return 0;
}
    
