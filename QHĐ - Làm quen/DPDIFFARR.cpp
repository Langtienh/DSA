#include <iostream>

using namespace std;

bool c[1000006];
int n, m, diff = 0, f[100006], a[100006];

int main() {
    scanf("%d%d", &n, &m); 
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=n; i; --i) {
        if (!c[a[i]]) ++diff, c[a[i]] = true;
        f[i] = diff;
    }
    while (m--) {
        scanf("%d", &n);
        cout << f[n] << "\n";
    }
    
    return 0;
}
    
