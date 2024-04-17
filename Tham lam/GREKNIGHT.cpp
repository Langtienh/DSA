#include <iostream>
#include <queue>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    int p, c, pos;
    
    bool operator < (const Data &other) const {
         return p < other.p;
    }
} P[100006];

llong sum[100006];
priority_queue<int, vector<int>, greater<int> > S;
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &P[i].p), P[i].pos = i;
    for(int i=1; i<=n; ++i) scanf("%d", &P[i].c);
    sort(P+1, P+n+1);
    llong T = 0;
    for(int i=1; i<=n; ++i) {
        sum[P[i].pos] = T + P[i].c;
        if (k == 0) continue;
        if (S.size() < k) T += P[i].c, S.push(P[i].c); 
        else {
            if (S.top() >= P[i].c) continue;
            else  {
                T -= S.top(); S.pop();
                T += P[i].c; S.push(P[i].c);
            }
        }
    }
    for(int i=1; i<=n; ++i) cout << sum[i] << " ";
    return 0;
    
}
    
