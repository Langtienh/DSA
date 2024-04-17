#pragma GCC optimze("O3")
#include <iostream>
#include <algorithm>
#include <deque>
#define fname "BOMB"
#define llong long long

using namespace std;

llong f[1006][11006];
int x[1006], y[1006], n, m, S[11006], n_stack = 0;

void enter() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d%d", &y[i], &x[i]);
}

void push(int i, int j) {
    while (n_stack && f[i-1][S[n_stack]] + 1LL*(j - S[n_stack]) / x[i] * y[i] <= f[i-1][j]) --n_stack;
    S[++n_stack] = j;
}

void process() {
    for(int i=0; i * x[1] <= m; ++i) f[1][i*x[1]] = 1LL*i*y[1];
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<x[i]; ++j) {
            for(int k = j; k <= m; k += x[i]) {
                push(i, k);
                f[i][k] = f[i-1][S[1]] + 1LL*(k - S[1]) / x[i] * y[i];
            }
            n_stack = 0;
        }
    }
    llong res = 0;
    for(int i=1; i<=n; ++i)
    for(int j=0; j<=m; ++j)
        res = max(res, f[i][j]);
    cout << res << "\n";
}

int main() {

    enter();
    process();

    return 0;
}
    
