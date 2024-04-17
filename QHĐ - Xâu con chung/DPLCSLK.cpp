#include <bits/stdc++.h>
#define maxs 2006

using namespace std;

int S1[maxs], S2[maxs];
int f[maxs][maxs], n, m;

void enter() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &S1[i]);
    for(int i=1; i<=m; ++i) scanf("%d", &S2[i]);
}

void init() {
    for(int i=2; i<=n+1; i++)
        for(int j=2; j<=m+1; j++)
            if (S1[i-1]==S2[j-1]) f[i][j] = f[i-2][j-2]+1;
            else f[i][j] = max(f[i][j-1], f[i-1][j]);
    cout << f[n+1][m+1];
}

int main() {
    enter();
    init();
    return 0;
}
    
