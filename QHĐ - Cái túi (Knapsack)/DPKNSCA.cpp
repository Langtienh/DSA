#include <iostream>

using namespace std;

bool f[20006];
int n, S, a[106];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n); S = 0;
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]), S+=a[i];
        for(int j=0; j<=S; ++j) f[j] = false;
        f[0] = true;
        for(int i=1; i<=n; ++i)
        for(int j=S; j>=a[i]; --j) f[j] |= f[j-a[i]];
        for(int i=0; i<=S; ++i)
            if (f[i]) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
    
