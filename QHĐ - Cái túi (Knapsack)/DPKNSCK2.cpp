#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong f[1006][1006];
int trace[1006][1006], x[1006], y[1006], n, m;

void enter() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d%d", &y[i], &x[i]);
}

void print_trace(int val, int pos) {
    int res[1006], num = 0;
    for(int i=0; i<=n; ++i) res[i] = 0;
    for(int i=pos; i>0; --i) {
        if (x[i] == 0) {
            res[i] = 1; ++num;
            continue;
        }
        res[i] = (val - trace[i][val]) / x[i];
        num += res[i];
        val = trace[i][val];
    }
    cout << num << "\n";
    for(int i=1; i<=n; ++i)
        if (res[i]) cout << i << " ";
}

void process() {
    f[1][x[1]] = y[1], trace[1][x[1]] = 0;
    for(int i=2; i<=n; ++i)
    for(int j=0; j<=m; ++j) {
        f[i][j] = f[i-1][j]; trace[i][j] = j;
        if (x[i] <= j && f[i][j] < f[i-1][j-x[i]] + y[i]) {
            trace[i][j] = j-x[i];
            f[i][j] = f[i-1][j-x[i]] + y[i];
        }
    }
    llong res = 0;
    int val = 0, pos = 0;
    for(int i=n; i>0; --i)
    for(int j=0; j<=m; ++j)
        if (res < f[i][j]) {
            res = f[i][j];
            pos = i;
            val = j;
        }
    print_trace(val, pos);
}

int main() {

    enter();
    process();

    return 0;
}
    
