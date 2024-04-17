#include <bits/stdc++.h>
#define maxs 106

using namespace std;

char S1[maxs], S2[maxs], S3[maxs];
int f[maxs][maxs][maxs], p, n, m;

void enter() {
    scanf("%d%d%d", &n, &m, &p);
    scanf("%s", S1+1); 
    scanf("%s", S2+1); 
    scanf("%s", S3+1); 
}

void init() {
    for(int i=0; i<=n; ++i)
    for(int j=0; j<=m; ++j)
    for(int k=0; k<=p; ++k) f[i][j][k] = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            for(int k=1; k<=p; ++k) 
            	if (S1[i]==S2[j] && S2[j] == S3[k]) 
            	    f[i][j][k] = f[i-1][j-1][k-1]+1;
            	else f[i][j][k] = max(f[i-1][j][k], max(f[i][j-1][k], f[i][j][k-1]));
    cout << f[n][m][p] << "\n";
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
    	enter();
     	init();
    }
    return 0;
}
    
