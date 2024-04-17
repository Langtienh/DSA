#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[16][106];
bool avail[16][106];

int get_res(int num, int cnt) {
    if (num == 0) return 0;
    if (cnt == 0) return 1;
    if (avail[num][cnt]) return dp[num][cnt];
    avail[num][cnt] = true;
    for(int i=0; i<=min(cnt, num-1); ++i) dp[num][cnt] += get_res(num-1, cnt-i);
    return dp[num][cnt];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d%d", &n, &k);
        cout << get_res(n, k) << "\n";
    }
    return 0;
}
    
