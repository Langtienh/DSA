#include <iostream>

using namespace std;

struct Data {
    int x, y, s;
} e[26], P[106];

int x[20], k, m, n, R, res = 0, sum = 0;
int avail[106];

int dist(Data A, Data B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

void back_track(int cnt) {
    for(int i=x[cnt - 1] + 1; i <= m-k+cnt; ++i) {
        x[cnt] = i;
        for(int j=1; j<=n; ++j)
            if (!avail[j] && dist(P[j], e[i]) <= R*R) {
                avail[j] = i;
                sum += P[j].s;
            }
        if (cnt == k) res = max(res, sum);
        else back_track(cnt+1);
        for(int j=1; j<=n; ++j)
            if (avail[j] == i) {
                avail[j] = 0;
                sum -= P[j].s;
            }
    }
}

int main() {
    scanf("%d%d", &k, &R);
    scanf("%d", &m);
    for(int i=1; i<=m; ++i) scanf("%d%d", &e[i].x, &e[i].y);
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d%d%d", &P[i].x, &P[i].y, &P[i].s);
    back_track(1);
    cout << res;
    return 0;
}
    
