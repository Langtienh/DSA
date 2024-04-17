#include <iostream>
#include <algorithm>
#include <queue>
#define llong long long

using namespace std;

struct Data {
    llong t, w;

    bool operator > (const Data &other) const {
        return t > other.t;
    }
} San, P[200006];

struct cmp {
    bool operator () (const Data &A, const Data &B) {
        return A.w - A.t > B.w - B.t;
    }
};

priority_queue<Data, vector<Data>, cmp> PQ;
int n;

int main() {
    scanf("%d", &n); --n; int res = 1;
    scanf("%I64d%I64d", &San.t, &San.w);
    for(int i=1; i<=n; ++i) scanf("%I64d%I64d", &P[i].t, &P[i].w);
    sort(P+1, P+n+1, greater<Data>());
    int l = 1;
    for(int &i = l; i<=n && P[i].t > San.t; ++i, ++res) PQ.push(P[i]);
    int Rank = res;
    while (San.t > 0 && !PQ.empty()) {
        Data p = PQ.top();
        if (San.t < p.w - p.t + 1) break;
        San.t -= p.w - p.t + 1;
        PQ.pop();
        --Rank;
        for(int &i = l; i<=n && P[i].t > San.t; ++i, ++Rank) PQ.push(P[i]);
        res = min(res, Rank);
    }
    cout << res;

    return 0;
}
    
