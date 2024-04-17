#include <iostream>

using namespace std;

int n, m;
int f[2][2106][2106];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int res = 0;
        scanf("%d%d", &n, &m);
        for(int i=1, a; i<=n; ++i) {
            scanf("%d", &a);
            for(int j=0; j<=m; ++j) {
                f[0][i][j] = max(f[0][i-1][j], f[1][i-1][j]);
                if (a <= j) f[1][i][j] = f[0][i-1][j-a] + a, res = max(res, f[1][i][j]);
            }
        }
        cout << res << " ";
    }
    return 0;
}
    
