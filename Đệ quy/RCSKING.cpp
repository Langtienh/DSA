#include <iostream>
#include <queue>

using namespace std;

const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

struct Point {
    int x, y;
};

int tx, ty, sx, sy, u1, v1, u2, v2, n;
bool avail[1006][1006];
bool colunm[1006], row[1006];
bool main_diagonal[2006], diagonal_filler[2006];

bool BFS() {
    if (sx == tx && sy == ty) return true;
    queue<Point> Q; Q.push({sx, sy}); avail[sx][sy] = true;
    do {
        Point u = Q.front(); Q.pop();
        for(int i=0; i<8; ++i) {
            Point v = {u.x + dx[i], u.y + dy[i]};
            if (1 <= v.x && v.x <= n && 1 <= v.y && v.y <= n)
            if (!avail[v.x][v.y] && !row[v.x] && !colunm[v.y]
                && !main_diagonal[v.x-v.y+1000] && !diagonal_filler[v.x+v.y]){
                if (v.x == tx && v.y == ty) return true;
                avail[v.x][v.y] = true;
                Q.push(v);
            }
        }
    } while (!Q.empty());
    return false;

}

int main() {
    cin >> n;
    cin >> u1 >> v1 >> u2 >> v2;
    row[u1] = row[u2] = true;
    colunm[v1] = colunm[v2] = true;
    main_diagonal[u1-v1+1000] = main_diagonal[u2-v2+1000] = true;
    diagonal_filler[u1+v1] = diagonal_filler[u2+v2] = true;
    cin >> sx >> sy;
    cin >> tx >> ty;
    if(BFS()) cout << "YES"; else cout << "NO";

    return 0;
}
    
