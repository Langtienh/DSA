#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define maxs 2006

using namespace std;

char S1[maxs], S2[maxs];
int f[maxs][maxs], t[maxs][maxs], n, m;
bool avail[maxs], avail1[maxs];

void enter() {
    scanf("%s", S1+1); n=strlen(S1+1);
    scanf("%s", S2+1); m=strlen(S2+1);
}

void process() {
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=m; ++j) f[i][j] = t[i][j] = 0, avail1[j] = false;
        avail[i] = false;
    }
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
    int m1 = m, n1 = n;
    while (m>0 && n>0) {
        if (m>0 && n>0 && t[n][m]==0) {
            res.push_back(S1[n]);
            m--, n--;
        } else if (n>0 && t[n][m]==1) n--;
        else if (m>0 && t[n][m]==-1) m--;
    }
    reverse(res.begin(), res.end());
    int j = 1, i = 1, k = 0;
    m = m1, n = n1;
    while (k < (int) res.size()) {
        while (i <= n && S1[i] != res[k]) ++i;
        while (j <= m && S2[j] != res[k]) ++j;
        avail[i] = avail1[j] = true; ++k, ++i, ++j;
    }
    i = 1, j = 1;
    while (i <= n && j <= m) {
        if (avail[i] != avail1[j]) {
            if (avail[i]) cout << S2[j++];
            else cout << S1[i++];
        } else {
            if (avail1[j] == false) cout << S1[i++] << S2[j++];
            else {
                cout << S2[j++];
                ++i;
            }
        }
    }
    while (i <= n) cout << S1[i++];
    while (j <= m) cout << S2[j++];
    cout << "\n";
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        enter();
        process();
        trace();
    }
    return 0;
}
    
