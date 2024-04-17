#include <bits/stdc++.h>
#define maxs 5006

using namespace std;

char S1[maxs], S2[maxs];
int f[maxs][maxs], t[maxs][maxs], n, m;

void enter() {
    scanf("%s", S1+1); n=strlen(S1+1); m = n;
    for(int i=1; i<=n; ++i) S2[i] = S1[n-i+1];
}

void init() {
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if (S1[i]==S2[j]) f[i][j] = f[i-1][j-1]+1, t[i][j]=0;
            else {
                if (f[i-1][j]>=f[i][j-1]) {
                    f[i][j] = f[i-1][j];
                    t[i][j]=1;
                } else f[i][j] = f[i][j-1], t[i][j]=-1;
            }
}

void trace() {
    vector<char> res;
    while (m>0 && n>0) {
        if (m>0 && n>0 && t[n][m]==0) {
            res.push_back(S1[n]);
            m--, n--;
        } else if (n>0 && t[n][m]==1) n--;
        else if (m>0 && t[n][m]==-1) m--;
     }
    //cout << res.size() << "\n";
    for(vector<char>::reverse_iterator i=res.rbegin(); i!=res.rend(); i++) cout << *i;
}

int main() {
    enter();
    init();
    trace();
    return 0;
}
    
