#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
    int val, pos;
    
    bool operator > (const Data &other) const {
        return val > other.val;
    }
} a[100006];

int n;
long long S = 0;

int main() {
    scanf("%d", &n);
    S += n;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i].val), a[i].pos = i;
    sort(a+1, a+n+1, greater<Data>());
    for(int i=1; i<=n; ++i) S += 1LL*a[i].val*(i-1);
    cout << S << "\n";
    for(int i=1; i<=n; ++i) cout << a[i].pos << " ";
    return 0;
}
    
