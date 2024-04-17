#include <iostream>
#include <algorithm>
#define pii pair<int, int>
#define llong long long

using namespace std;

int n, k, s, t, b[200006];
pii a[200006];

bool check(int x) {
    llong sum = 0;
    for(int i=1; i<=k; ++i) {
        llong dist = b[i] - b[i-1];
        if (x < dist) return false;
        llong fast = x - dist;
        fast = min(fast, dist);
        if (fast + dist > x) return 0;
        sum += 2*dist - fast;
    }
    return sum <= t;
}

int main() {
    int mmax = 0;
    scanf("%d%d%d%d", &n, &k, &s, &t);
    for(int i=1; i<=n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
        mmax = max(mmax, a[i].second);
    }
    for(int i=1; i<=k; ++i) scanf("%d", &b[i]);
    sort(b+1, b+k+1);
    b[0] = 0; b[++k] = s;
    int l = 1, r = mmax, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    if (ans == -1) cout << -1;
    else {
        int mmin = 2e9+7;
        for(int i=1; i<=n; ++i)
            if (a[i].second >= ans) mmin = min(mmin, a[i].first);
        cout << mmin;
    }
    return 0;
}
    
