#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

using namespace std;

bool avail[106][200006];
int n, S, a[106];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n); S = 0;
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]), S+=a[i];
        avail[0][S] = true;
        for(int i=1; i<=n; ++i)
        for(int j=0; j <= 2*S; ++j) {
            avail[i][j] = false;
            if (j >= a[i]) avail[i][j] |= avail[i-1][j-a[i]];
            if (j + a[i] <= 2*S) avail[i][j] |= avail[i-1][j+a[i]];
        }
        if (avail[n][S]) cout << "YES\n";
        else cout << "NO\n";
        avail[0][S] = false;
    }
    return 0;
}
    
