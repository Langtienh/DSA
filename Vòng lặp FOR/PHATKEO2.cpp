#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    long long k; cin >> k;
    int l=1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l+r) >> 1;
    	if (((3LL*(mid-1)*mid) >> 1) + mid <= k) {
    	    ans = mid;
    	    l = mid + 1;
    	} else r = mid - 1;
    }
    cout << ans;
    
    return 0;
}
    
