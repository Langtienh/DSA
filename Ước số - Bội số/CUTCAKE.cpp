#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int pre=0, a, G = 360, m=1;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a);
        if (m == 1 && a > 0 && a < 360) G = a, ++m;
        else if (a - pre > 0 && a < 360) G = __gcd(G, a - pre), ++m;
        pre = a;
    }
    G = 360/__gcd(360, G);
    cout << G - m;
    return 0;
}
    
