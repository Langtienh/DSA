#include <iostream>
#include <algorithm>

struct Data {
    int val, pos;

    bool operator < (const Data &other) const {
        return val < other.val || (val == other.val && pos < other.pos);
    }
} P[100006];

using namespace std;

int main() {
    int n, Ti;
    scanf("%d%d", &n, &Ti);
    for(int i=1; i<=n; ++i) scanf("%d", &P[i].val), P[i].pos = i;
    sort(P+1, P+n+1);
    for(int i=1; i<=n; ++i)
        if (P[i].pos == Ti) {
            cout << i;
            return 0;
        }

    return 0;
}
    
