#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
    int val, pos;
    
    bool operator < (const Data &other) const {
        return val < other.val;
    }
} a[200006];

int num[200006], n;
bool avail[200006];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i].val), a[i].pos = i;
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) 
        if ((i == n || a[i].val != a[i+1].val) && a[i].val <= n) {
            avail[a[i].val] = true;
            num[a[i].pos] = a[i].val;
        }
    int l = 1;
    for(int i=1; i<=n; ++i) {
        while (num[l]) ++l;
        if (!avail[i]) 
            num[l] = i;
    }
    for(int i=1; i<=n; ++i) cout << num[i] << " ";
    return 0;
}
    
