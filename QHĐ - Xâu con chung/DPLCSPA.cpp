#include <iostream>
#include <algorithm>

using namespace std;

int n, f[5006][5006];
char S1[5006], S2[5006];

int main() {
    scanf("%d", &n);
    scanf("%s", S1+1);
    for(int i=1; i<=n; ++i) S2[i] = S1[n-i+1];
    for(int i=0; i<=n; ++i) f[i][0] = f[0][i] = i;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
        if (S1[i]==S2[j]) f[i][j] = f[i-1][j-1];
        else f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1);
    cout << f[n][n]/2;
    return 0;
}
    
