#pragma GCC optimize("O3")
#include <iostream>
#include <queue>
#define sint short int

using namespace std;

const sint dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const sint dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
bool avail[11][11];
int f[16][16][16];

bool check(sint x, sint y) {
    return (1 <= x && x <= 10 && 1 <= y && y <= 10);
}

sint n, num;

void init() {
    for(sint i=1; i<=10; ++i)
    for(sint j=1; j<=10; ++j) avail[i][j] = false;
    num = 0;
}

void _try(sint x, sint y, sint cnt) {
    for(sint i=0, u, v; i<8; ++i) {
        u = x + dx[i], v = y + dy[i];
        if (check(u, v)) {
            if (cnt < n) _try(u, v, cnt+1);
            else if (!avail[u][v]) {
            	avail[u][v] = true;
            	++num;
            }
        }
    }
}

int main() {
    sint t, x, y;
    scanf("%hd", &t);
    while (t--) {
        scanf("%hd%hd%hd", &x, &y, &n);
        if (n > 5) {
             cout << 50 << "\n";
             continue;
        }
        if(f[x][y][n]) {
            cout << f[x][y][n] << "\n";
            continue;
        }
        init();
        _try(x, y, 1);
        f[x][y][n] = f[y][x][n] = f[10-y+1][x][n] = f[y][10 - x + 1][n] = num;
        x = 10-x+1; y = 10-y+1;
        f[x][y][n] = f[y][x][n] = f[10-y+1][x][n] = f[y][10 - x + 1][n] = num;
        cout << num << "\n";
    }
    return 0;
}
    
