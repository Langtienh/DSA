#include <iostream>
#include <algorithm>

using namespace std;

int f[2][206][206], n, m1, m2;

int main() {
    scanf("%d%d%d", &m1, &m2, &n);
    int ok =0, res = 0;
    while(n--) {
        int v, w;
        scanf("%d%d", &v, &w);
        for(int i=m1; i>=0; --i)
        for(int j=m2; j>=0; --j) {
            f[ok][i][j] = f[1-ok][i][j];
            if (w <= i) f[ok][i][j] = max(f[ok][i][j], f[1-ok][i-w][j] + v);
            if (w <= j) f[ok][i][j] = max(f[ok][i][j], f[1-ok][i][j-w] + v);
            res = max(res, f[ok][i][j]);
        }
        ok = 1 - ok;
    }
    cout << res;
    return 0;
}
    
