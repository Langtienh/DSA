#include <iostream>
#include <set>

using namespace std;

long long a[1000006];
set<long long> B;

int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%I64d", &a[i]);
    for(int i=1; i<=n; ++i) {
        long long b; scanf("%I64d", &b);
        B.insert(b);
    }
    int res = 0;
    for(int i=1; i<=n; ++i)
       if (B.count(a[i])) ++res;
    cout << res;
    
    return 0;
}
    
