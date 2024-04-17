#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
    int val, pos;
    
    bool operator < (const Data &other) const {
         return val < other.val;
    }
} P[200006];

int n, a[200006];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &P[i].val), P[i].pos = i;
    sort(P+1, P+n+1);
    int num = 0;
    for(int i=1; i<=n; ++i, ++num) {
        if (num < P[i].val) num = P[i].val;
        a[P[i].pos] = num;
    }
    for(int i=1; i<=n; ++i) cout << a[i] << " ";
    return 0;
}
    
