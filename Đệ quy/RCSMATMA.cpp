#include <iostream>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int a[26][26], m, n, res = 0, num = 0;
bool avail[26][26];

void _try(int x, int y) {
    ++num; res = max(res, num); avail[x][y] = true;
    for(int i=0; i<4; ++i) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (1 <= u && u <= m && 1 <= v && v <= n)
            if (a[u][v] >= a[x][y] && !avail[u][v]) _try(u, v);
    }
    --num; avail[x][y] = false;
}

int main() {
    scanf("%d%d\n", &m, &n); char c;
    for(int i=1; i<=m; ++i, scanf("\n"))
        for(int j=1; j<=n; ++j) {
            scanf("%c", &c);
            a[i][j] = c - 'A' + 1;
        }
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) {
        _try(i, j);
    }
    cout << res;

    return 0;
}
    
