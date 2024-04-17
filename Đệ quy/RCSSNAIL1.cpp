#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int a[1006][1006], m, n;

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
    cout << num;
}

int main() {
    int x, y;
    scanf("%d%d%d%d", &m, &n, &x, &y);
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) scanf("%d", &a[i][j]);
    BFS(x, y);
    return 0;
}
    
