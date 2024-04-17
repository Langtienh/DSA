#include <iostream>

using namespace std;

int f[1006], n, m, a[206];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &m, &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]); f[0] = 0;
        for(int i=1; i<=m; ++i) {
            f[i] = 1e9;
            for(int j=1; j<=n; ++j)
                if (a[j]<=i) f[i] = min(f[i], f[i-a[j]]+1);
        }
        if (f[m] == 1e9) {
            cout << "-1\n" ;
            continue;
        }
        cout << f[m] << "\n";
    }
    return 0;
}
    
