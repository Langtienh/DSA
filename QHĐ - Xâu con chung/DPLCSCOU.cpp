#include <bits/stdc++.h>
#define maxs 5006

using namespace std;

char S1[maxs], S2[maxs];
int f[maxs][maxs], n, m;
const int base = 25071987;

void enter() {
    scanf("%s", S1+1); n=strlen(S1+1);
    scanf("%s", S2+1); m=strlen(S2+1);
}

void init() {
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if (S1[i]==S2[j]) f[i][j] = (f[i-1][j] + f[i][j-1] + 1) % base;
            else f[i][j] = (f[i-1][j] + f[i][j-1] - f[i-1][j-1]) % base;
    cout << (f[n][m] % base + base) % base;
}  

int main() {
    enter();
    init();
    return 0;
}
    
