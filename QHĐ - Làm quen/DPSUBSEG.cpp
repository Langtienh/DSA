#include <iostream>

using namespace std;

int n, a[100006], f[100006];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        f[n+1] = 0;
        for(int i=n; i; --i) 
           if (1LL*a[i] * a[i+1] < 0) f[i] = f[i+1] + 1;
           else f[i] = 1;
        for(int i=1; i<=n; ++i) cout << f[i] << " ";
        putchar('\n');
    }
}
    
