#include <iostream>
#include <algorithm>
#define fname "FINDAB"
#define llong long long

using namespace std;

llong a[100006], b[100006];
int n;

void enter() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
}

int  _binary_search(llong x) {
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (b[mid] == x) return 1;
        if (b[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

void process() {
    sort(b+1, b+n+1);
    int res = 0;
    for(int i=1; i<=n; ++i) res += _binary_search(a[i]);
    cout << res;
}

int main() {

    enter();
    process();

    return 0;
}
    
