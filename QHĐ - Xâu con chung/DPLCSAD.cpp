#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxs = 1106;
int f1[maxs][maxs], f2[maxs][maxs], n, m, block;
char S1[maxs], S2[maxs];
bool avail[1106][26];

void process() {
    int res = 0;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
    if (S1[i] == S2[j]) f1[i][j] = f1[i-1][j-1] + 1;
    else f1[i][j] = max(f1[i-1][j], f1[i][j-1]);
    block = f1[n][m];
    for(int i=n; i; --i)
    for(int j=m; j; --j)
    if (S1[i] == S2[j]) f2[i][j] = f2[i+1][j+1] + 1;
    else f2[i][j] = max(f2[i+1][j], f2[i][j+1]);
    for(int i=0; i<=n; ++i)
    for(int j=1; j<=m; ++j)
    if (f1[i][j-1] + f2[i+1][j+1] == block && !avail[i][S2[j]-'a']) avail[i][S2[j]-'a'] = true, ++res;
    cout << res;
}

int main() {
    scanf("%s", S1+1); n = strlen(S1+1);
    scanf("%s", S2+1); m = strlen(S2+1);
    process();
    return 0;
}
    
