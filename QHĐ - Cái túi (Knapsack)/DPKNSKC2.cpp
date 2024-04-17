#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong f[1006][11006];
int trace[1006][11006], x[1006], y[1006], n, m, S[11006], n_stack = 0;

void enter() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d%d", &y[i], &x[i]);
}

void print_trace(int val, int pos) {
    int res[1006];
    for(int i=0; i<=n; ++i) res[i] = 0;
    for(int i=pos; i>0; --i) {
        res[i] = (val - trace[i][val]) / x[i];
        val = trace[i][val];
    }
    for(int i=1; i<=n; ++i) cout << res[i] << "\n";
}

void push(int i, int j) {
    while (n_stack && f[i-1][S[n_stack]] + 1LL*(j - S[n_stack]) / x[i] * y[i] <= f[i-1][j]) --n_stack;
    S[++n_stack] = j;
}

void process() {
    for(int i=0; i * x[1] <= m; ++i) f[1][i*x[1]] = 1LL*i*y[1], trace[1][i*x[1]] = 0;
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<x[i]; ++j) {
            for(int k = j; k <= m; k += x[i]) {
                push(i, k);
                f[i][k] = f[i-1][S[1]] + 1LL*(k - S[1]) / x[i] * y[i];
                trace[i][k] = S[1];
            }
            n_stack = 0;
        }
    }
    llong res = 0;
    int val = 0, pos = 0;
    for(int i=1; i<=n; ++i)
    for(int j=0; j<=m; ++j)
        if (res < f[i][j]) {
            res = f[i][j];
            pos = i;
            val = j;
        }
    cout << res << "\n";
    print_trace(val, pos);
}

int main() {

    enter();
    process();

    return 0;
}
    
