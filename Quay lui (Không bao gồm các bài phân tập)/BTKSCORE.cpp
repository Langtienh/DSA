#include <iostream>

using namespace std;

int a[26][26], trace[26][26][2006], S, n, m;
bool avail[26][26][2006];
int V[26];

int main() {
    scanf("%d%d%d", &S, &n, &m);
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) scanf("%d", &a[i][j]);
    for(int i=1; i<=m; ++i) avail[1][i][a[i][1]] = true;
    for(int j=2; j<=n; ++j)
    for(int i=1; i<=m; ++i)
    for(int k=a[i][j]; k<=S; ++k)
    for(int l=1; l<=m; ++l)
        if (a[l][j-1] <= a[i][j])
        if (avail[j-1][l][k - a[i][j]]) {
            trace[j][i][k] = l;
            avail[j][i][k] = true;
        }
    for(int i=1; i<=m; ++i)
        if (avail[n][i][S]) {
            cout << "YES\n";
            int pos = i;
            for(int j=n; j; --j) {
                V[j] = a[pos][j];
                int pos1 = pos;
                pos = trace[j][pos][S];
                S -= a[pos1][j];
            }
            for(int j=1; j<=n; ++j) cout << V[j] << " ";
            return 0;
        }

    cout << "NO";
    return 0;
}
    
