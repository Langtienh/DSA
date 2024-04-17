#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

int n, a[506];
llong num[506], V;
const int oo = 1e8;
int trace[506][5006], f[506][5006];
vector<int> Q;

void push(int i, int k) {
    while (!Q.empty() && f[i-1][Q.back()] + (k - Q.back()) / a[i] >= f[i-1][k]) Q.pop_back();
    Q.push_back(k);
}

void print(int p) {
    for(int i=p; i; --i) {
        num[i] += (V - trace[i][(int) V]) / a[i];
        V = trace[i][(int) V];
    }
    for(int i=1; i<=n; ++i) cout << num[i] << " ";
}

int main() {
    scanf("%I64d%d", &V, &n);
    int mmax = 0, p = 0;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        if (mmax < a[i]) {
            mmax = a[i];
            p = i;
        }
    }
    if (V > 1000) {
        num[p] = (V-1000) / mmax - 1;
        V -= num[p] * mmax;
    }
    int p1 = p;
    for(int i=1; i<=n; ++i)
    for(int j=0; j<=V; ++j) f[i][j] = oo;
    for(int i=0; i * a[1] <= V; ++i) f[1][i*a[1]] = i;
    for(int i=2; i<=n; ++i)
    for(int j=0; j<a[i]; ++j) {
        for(int k=j; (llong) k<=V; k += a[i]) {
            push(i, k);
            f[i][k] = f[i-1][Q.front()] + (k - Q.front()) / a[i];
            trace[i][k] = Q.front();
        }
        Q.clear();
    }
    mmax = 1e8, p = 0;
    for(int i=1; i<=n; ++i)
        if (mmax > f[i][V]) {
            mmax = f[i][V];
            p = i;
        }
    if (mmax == 1e8) {
        cout << -1;
        return 0;
    }
    cout << mmax + num[p1] << "\n";
    print(p);
    return 0;
}
    
