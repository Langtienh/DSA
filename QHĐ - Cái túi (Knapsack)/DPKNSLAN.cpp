#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int S, n, w;
llong f[1006];

int main() {
    while (scanf("%d", &S)!=-1) {
        scanf("%d", &w);
        scanf("%d", &n);
        for(int i=1; i<=S; ++i) f[i] = 0;
        for(int i=1, d, v; i<=n; ++i) {
            scanf("%d%d", &d, &v); d = 3*d*w;
            if (d > S) continue;
            for(int j=S; j>=d; --j) f[j] = max(f[j], f[j-d] + v);
        }
        cout << f[S] << "\n";
    }
    return 0;
}
    
