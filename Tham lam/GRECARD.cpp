#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
    int a, b;

    bool operator > (const Data &other) const {
        return b > other.b || (b == other.b && a > other.a);
    }

} P[100006];

long long S[100006];
int n;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d%d", &P[i].a, &P[i].b);
    sort(P+1, P+n+1, greater<Data>());
    long long res = 0;
    int d = 1;
    for(int i=1; i<=n; ++i)
        if (P[i].b > 0) {
            --d; d += P[i].b;
            res += P[i].a;
        } else {
            for(int j=i; j<=n && d > 0; ++j) res += P[j].a, --d;
            break;
        }
    cout << res;
    return 0;
}
    
