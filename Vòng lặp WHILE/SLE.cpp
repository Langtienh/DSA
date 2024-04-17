#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong get_ans(int mid) {
    if ((mid & 1) == 0) mid--;
    return (((1LL*mid - 1) >> 1) + 1) * (1LL*mid+1) >> 1;
}

int n;

void process() {
    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (get_ans(mid) >= n) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << get_ans(ans);
}

int main() {
    scanf("%d", &n);
    process();
    return 0;
}
    
