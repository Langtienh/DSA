#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    int h, cost;

    bool operator < (const Data &other) const {
        return h < other.h;
    }
} P[200006];

int n;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &P[i].h);
    for(int i=1; i<=n; ++i) scanf("%d", &P[i].cost);
    sort(P+1, P+n+1);
    llong sum = 0, cost1 = 0, cost2 = 0;
    for(int i=n; i>1; --i) sum += 1LL*P[i].cost*(P[i].h - P[1].h), cost2 += P[i].cost;
    llong res = sum;
    for(int i=2; i<=n; ++i) {
        cost1 += P[i-1].cost;
        sum += (cost1 - cost2)*(1LL*P[i].h - P[i-1].h);
        res = min(res, sum);
        cost2 -= P[i].cost;
    }
    cout << res;
    return 0;
}
    
