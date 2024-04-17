#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    int a, b;

    bool operator < (const Data &other) const {
        return b < other.b;
    }
} P[100006];

int main() {
    int n, r, avg;
    llong S = 0, sum, res = 0;
    scanf("%d%d%d", &n, &r, &avg); sum = 1LL*n*avg;
    for(int i=1; i<=n; ++i) scanf("%d%d", &P[i].a, &P[i].b), S += P[i].a;
    sort(P+1, P+n+1);
    int i=1;
    while (S < sum) {
        while (P[i].a >= r) ++i;
        if (r - P[i].a + S < sum) res += 1LL*P[i].b*(r - P[i].a), S += r - P[i].a, P[i].a = r;
        else {
            sum -= S;
            res += sum * P[i].b;
            break;
        }
    }
    cout << res;
    return 0;
}
    
