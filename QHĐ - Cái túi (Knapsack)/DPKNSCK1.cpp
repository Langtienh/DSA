#include <iostream>
#define llong long long

using namespace std;

llong f[2000006];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1, a, b; i<=n; ++i) {
        scanf("%d%d", &b, &a);
        for(int j=m; j>=a; --j) f[j] = max(f[j], f[j-a] + b);
    }
    cout << f[m];
    return 0;
}
    
