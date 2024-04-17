#include <iostream>

using namespace std;

int n, m, f[506];

int main() {
    scanf("%d%d", &m, &n);
    while (m != 0 && n != 0) {
        for(int i=0; i<=m; ++i) f[i] = 0;
        for(int i=1, a, b; i<=n; ++i) {
            scanf("%d%d", &a, &b);
            for(int i=m; i>=a; --i) f[i] = max(f[i], f[i-a]+b);
        }
        for(int i=m; i>=0; --i)
            if (i == 0 || f[i] > f[i-1]) {
                cout << i << " " << f[i] << "\n";
                break;
            }
        scanf("%d%d", &m, &n);
    }
    return 0;
}
    
