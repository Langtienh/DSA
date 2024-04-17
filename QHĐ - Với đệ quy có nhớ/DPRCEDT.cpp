#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int f[2006][2006], n, m;
bool avail[2006][2006];
char S1[2006], S2[2006];

int get_res(int i, int j) {
    if (avail[i][j]) return f[i][j];
    avail[i][j] = true;
    if (S1[i] == S2[j]) return f[i][j] = get_res(i-1, j-1);
    else return f[i][j] = min(min(get_res(i-1, j), get_res(i, j-1)), get_res(i-1, j-1))+1;
}

void init() {
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j) avail[i][j] = false, f[i][j] = 0;
    for(int i=0; i<=n; ++i) f[i][0] = i, avail[i][0] = true;
    for(int j=0; j<=m; ++j) f[0][j] = j, avail[0][j] = true;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", S1+1); n = strlen(S1+1);
        scanf("%s", S2+1); m = strlen(S2+1);
        init();
        cout << get_res(n, m) << "\n";
    }
    return 0;
}
    
