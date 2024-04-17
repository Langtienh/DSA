#include <iostream>

using namespace std;

int S, a[106], b[106], n, m;
const int base = 1e9+7;
int f[106][100006];

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        S += b[i];
    }
    for(int i=1; i<=n; ++i)
    for(int j=0; j<=S; ++j) f[i][j] = base;
    f[1][0] = 0; f[1][b[1]] = a[1];
    for(int i=2; i<=n; ++i)
    for(int j=0; j<=S; ++j) {
        f[i][j] = f[i-1][j];
        if (b[i] <= j) f[i][j] = min(f[i][j], f[i-1][j-b[i]] + a[i]);
    }
    for(int j=S; j>=0; --j)
    for(int i=1; i<=n; ++i)
    if (f[i][j] <= m) {
        cout << j;
        return 0;
    }
    return 0;
}
    
