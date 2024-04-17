#include <iostream>
#include <algorithm>
#include <stack>
#define llong long long

using namespace std;

int n, m, k;
llong f[1506][1506];

int main() {
    scanf("%d%d%d", &m, &n, &k);
    for(int i=1; i<=k; ++i) {
        int u, v, r, c, g;
        scanf("%d%d%d%d%d", &u, &v, &r, &c, &g);
        f[u][v] += g;
        f[r+1][v] -= g;
        f[u][c+1] -= g;
        f[r+1][c+1] += g;
    }
    for(int i=1; i<=m; ++i, putchar('\n'))
    for(int j=1; j<=n; ++j) {
        f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        cout << f[i][j] + 1 << " ";
    }
    return 0;
}
    
