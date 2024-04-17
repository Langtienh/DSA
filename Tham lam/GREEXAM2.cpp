/// Code by Ha Van Hoang T6 THPT Chuyen Binh Long
#include <iostream>
#include <algorithm>
#define pii pair<pair<int, int> , int>
#define mk make_pair

using namespace std;

int t, n, pos[200006];
pii a[200006];

bool check(int x) {
    int T = 0, num = 0;
    for(int i=1; i<=n && T + a[i].first.second <= t; ++i)
        if (a[i].first.first >= x) ++num, T += a[i].first.second;
    return num >= x;
}

void print(int x) {
    int T = 0, block = x;
    cout << x << "\n";
    for(int i=1; i<=n && T + a[i].first.second <= t && x > 0; ++i)
        if (a[i].first.first >= block) cout << a[i].second << " ", T += a[i].first.second, --x;
}

int main() {
    scanf("%d%d", &n, &t);
    for(int i=1; i<=n; ++i) scanf("%d%d", &a[i].first.first, &a[i].first.second), a[i].second = i;
    sort(a+1, a+n+1, [] (const pii &A, const pii &B) {
        return A.first.second < B.first.second || (A.first.second == B.first.second && A.first.first > B.first.first);
    });
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans << "\n";
    if (ans == 0) cout << 0;
    else print(ans);
    return 0;
}
    
