#include <iostream>
#define llong long long

using namespace std;

llong f[100006];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for(int i=1, a; i<=n; ++i) {
            scanf("%d", &a);
            if (i <= 2) f[i] = a;
            else f[i] = max(f[i-2], f[i-3]) + a;
        }
        cout << max(f[n-1], f[n]); putchar('\n');
    }
    
    return 0;
}
    
