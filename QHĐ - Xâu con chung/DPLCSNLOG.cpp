#include <iostream>
#define ull unsigned long long

using namespace std;

int a[100006], bit[100006], n, m, pos[100006];

void update_bit(int p, int val) {
    for(; p<=n; p += (p & (-p))) bit[p] = max(bit[p], val);
}

int query(int p) {
    int ans = 0;
    for(; p>0; p -= (p & (-p))) ans = max(ans, bit[p]);
    return ans;
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; ++i) scanf("%d", &a[i]);
    for(int i=1, b; i<=n; ++i) {
        scanf("%d", &b);
        pos[b] = i;
    }
    int res = 0;
    for(int i=1; i<=m; ++i)
        if (pos[a[i]] > 0) {
            int best = query(pos[a[i]]-1)+1;
            res = max(res, best);
            update_bit(pos[a[i]], best);
        }
    cout << res;
    return 0;
}
    
