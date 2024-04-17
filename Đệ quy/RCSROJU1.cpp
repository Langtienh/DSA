#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x, y;
} trace[506][506], R, J;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
int m, n;
bool avail[506][506];
int deg[506][506];

bool check(int x, int y) {
    return 1 <= x && x <= m && 1 <= y && y <= n && !avail[x][y];
}

bool BFS() {
    queue<Point> Q; Q.push(J);
    do {
        Point u = Q.front(); Q.pop();
        for(int i=0; i<4; ++i) {
            Point v = {u.x + dx[i], u.y + dy[i]};
            if (check(v.x, v.y)) {
                avail[v.x][v.y] = true;
                deg[v.x][v.y] = deg[u.x][u.y] + 1;
                trace[v.x][v.y] = u;
                if (v.x == R.x && v.y == R.y) return true;
                Q.push(v);
            }
        }
    } while (!Q.empty());
    return false;
}

int main() {
    scanf("%d%d\n", &m, &n); char c;
    for(int i=1; i<=m; ++i, scanf("\n"))
    for(int j=1; j<=n; ++j) {
        scanf("%c", &c);
        if (c == 'J') {
            avail[i][j] = true;
            J = {i, j};
        } else if (c == 'R') {
            avail[i][j] = false;
            R = {i, j};
        } else if (c == 'o') avail[i][j] = false;
        else avail[i][j] = true;
    }
    if(BFS()) cout << "YES";
    else cout << "NO";

    return 0;
}
    
