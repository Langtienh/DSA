#include <iostream>
#include <deque>
#include <algorithm>
#define llong long long

using namespace std;

llong f[1005][1005], res = -1e18;
int n, m, k;

int main() {
    scanf("%d%d%d", &m, &n, &k);
    for (int i=1; i<=m; ++i)
    for (int j=1, a; j<=n; ++j) {
        scanf("%d", &a);
        if (k == 1) {
            res = max(res, 1LL*a);
            continue;
        }
        f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a;
        if (k <= min(i, j)) {
            llong tmp = f[i-1][j-1] - f[i-k+1][j-1] - f[i-1][j-k+1] + f[i-k+1][j-k+1];
            tmp = f[i][j] - f[i][j-k] - f[i-k][j] + f[i-k][j-k] - tmp;
            res = max(res, tmp);
        }
    }
    cout << res;
    return 0;
}
    
