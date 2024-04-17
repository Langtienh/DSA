#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

using namespace std;

bool R[1006][1006], D[1006][1006];
int n, m;
char S[1006];

int main() {
    int p; cin >> p;
    while (p--) {
        cin >> m >> n;
        for(int i=1; i<=m; ++i) {
            scanf("%s", S+1);
            for(int j=1; j<=n; ++j)
                if (S[j] == 'C') R[i][j] = D[i][j] = true;
                else R[i][j] = D[i][j] = false;
        }
        for(int i=0; i<=m+1; ++i) R[i][n+1] = false;
        for(int j=0; j<=n+1; ++j) D[m+1][j] = false;
        int res = 0;
        for(int j=n; j; --j) for(int i=m; i; --i) R[i][j] |= R[i][j+1];
        for(int i=m; i; --i) for(int j=n; j; --j) D[i][j] |= D[i+1][j];
        for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) res += !(R[i][j] | D[i][j]);
        cout << res << "\n";
    }
    return 0;
}
    
