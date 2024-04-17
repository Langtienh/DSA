#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int cnt = 0, a[1006][1006], m, n;
int V[1000006];

void BFS(int sx, int sy) {
    int num = 1;
    queue<int> X, Y;
    X.push(sx), Y.push(sy); a[sx][sy] = 1;
    do {
        int x = X.front(); X.pop();
        int y = Y.front(); Y.pop();
        for(int i=0; i<4; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (1 <= u && u <= m && 1 <= v && v <= n && a[u][v] == 0) {
                ++num;
                a[u][v] = 1;
                X.push(u);
                Y.push(v);
            }
        }
    } while (!X.empty());
    V[cnt] = num;
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) scanf("%d", &a[i][j]);
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j)
        if (a[i][j] == 0) ++cnt, BFS(i, j);
    sort(V+1, V+cnt+1);
    cout << V[cnt];
    return 0;
}
    
