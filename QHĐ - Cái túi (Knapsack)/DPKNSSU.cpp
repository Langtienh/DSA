#include <iostream>
#define llong long long

using namespace std;

llong f[10006];
int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    f[0] = 1;
    for(int i=1, a; i<=n; ++i) {
        scanf("%d", &a);
        for(int j=m; j>=a; --j) f[j] += f[j-a];
    }
    if (k > f[m]) cout << f[m]; else cout << "ENOUGH";
    return 0;
}
    
