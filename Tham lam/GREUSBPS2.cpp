#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data  {
    int cost, kind;

    bool operator < (const Data &other) const {
        return cost < other.cost;
    }
} P[300006];

int a, b, c, m, num=0;
llong Cost = 0;

int main() {
    scanf("%d%d%d", &a, &b, &c);
    scanf("%d", &m);
    char S[6];
    for(int i=1; i<=m; ++i) {
        scanf("%d", &P[i].cost);
        scanf("%s", S+1);
        if (S[1] == 'U') P[i].kind = 1; else P[i].kind = 2;
    }
    sort(P+1, P+m+1);
    for(int i=1; i<=m; ++i) {
        if (a > 0 && P[i].kind == 1) Cost += P[i].cost, --a, ++num;
        else if (c > 0 && P[i].kind == 1) Cost += P[i].cost, --c, ++num;
        if (b > 0 && P[i].kind == 2) Cost += P[i].cost, --b, ++num;
        else if (c > 0 && P[i].kind == 2) Cost += P[i].cost, --c, ++num;
    }
    cout << num << " " << Cost;
    return 0;
}
    
