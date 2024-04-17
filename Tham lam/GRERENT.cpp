#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Point {
    int x, kind;
    int pos;

    bool operator < (const Point &other) const {
        return x < other.x || (x == other.x && kind < other.kind);
    }
} P[400006];

int room[200006], n;

int main() {
    stack<int> S;
    scanf("%d", &n); n *= 2;
    for(int i=1; i<=n; ++i) {
        if (i <= n/2) S.push(n/2-i+1);
        scanf("%d", &P[i].x);
        if (i > n/2) P[i].kind = 0, P[i].x += P[i-n/2].x;
        else P[i].kind = 1;
        if (i <= n/2) P[i].pos = i;
        else P[i].pos = i - n/2;
    }
    sort(P+1, P+n+1);
    int res = 0;
    for(int i=1; i<=n; ++i)
        if (P[i].kind == 1) {
            room[P[i].pos] = S.top(); S.pop();
            res = max(res, room[P[i].pos]);
        } else S.push(room[P[i].pos]);
    cout << res;

    return 0;
}
    
