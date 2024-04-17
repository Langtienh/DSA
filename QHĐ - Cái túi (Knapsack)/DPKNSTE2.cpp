#include <iostream>
#include <algorithm>
#include <deque>
#define llong long long

using namespace std;

deque<int> DQ;
llong f[506][50006];
int trace[506][50006], x[506], y[506], z[506], n, m;

void enter() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d%d%d", &x[i], &y[i], &z[i]);
}

void print_trace(int val, int pos) {
    int res[506];
    for(int i=0; i<=n; ++i) res[i] = 0;
    for(int i=pos; i>0; --i) {
        if (x[i] == 0) {
            res[i] =  z[i];
            continue;
        };
        res[i] = (val - trace[i][val]) / x[i];
        val = trace[i][val];
    }
    for(int i=1; i<=n; ++i) cout << res[i] << "\n";
}

void push(int i, int j) {
    while (!DQ.empty() && f[i-1][DQ.back()] + (j - DQ.back()) / x[i] * y[i] <= f[i-1][j]) DQ.pop_back();
    DQ.push_back(j);
}

void pop(int i) {
    while (!DQ.empty() && DQ.front() < i) DQ.pop_front();
}

void process() {
    for(int i=0; i * x[1] <= m && i <= z[1]; ++i) f[1][i*x[1]] = i*y[1], trace[1][i*x[1]] = 0;
    for(int i=2; i<=n; ++i) {
        if (x[i] == 0) {
            for(int j=0; j<=m; ++j) f[i][j] = f[i-1][j] + y[i] * z[i];
            continue;
        }
        for(int j=0; j<x[i]; ++j) {
            for(int k = j; k <= m; k += x[i]) {
                pop(k - z[i]*x[i]);
                push(i, k);
                int top_front = DQ.front();
                f[i][k] = f[i-1][top_front] + (k - top_front) / x[i] * y[i];
                trace[i][k] = top_front;
            }
            DQ.clear();
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
}

int main() {

    enter();
    process();

    return 0;
}
    
