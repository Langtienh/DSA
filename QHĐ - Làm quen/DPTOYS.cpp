#pragma GCC optimize("O2")
#include <iostream>
#define llong long long

using namespace std;

int n;
llong f[100009];
int a[100009];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=n+1; i<=n+5; ++i) a[i] = 0;
        n+=5; f[1] = 0; if((n & 1) == 0) --n;
        for(int i=3; i<=n; i+=2) {
            f[i] = f[i-2] + a[i-2];
            if (i > 4) f[i] = max(f[i], f[i-4] + a[i-4] + a[i-3]);
            if (i > 6) f[i] = max(f[i], f[i-6] + a[i-6] + a[i-5] + a[i-4]);
        }
        cout << f[n] << "\n";
    }
}
    
