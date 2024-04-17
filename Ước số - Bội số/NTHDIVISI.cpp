#include <iostream>
#include <algorithm>
#define fname "NTHDIVISI"
#define llong long long

using namespace std;

llong a, b, n, _lcm_a_b;

void enter() {
    scanf("%I64d%I64d%I64d", &a, &b, &n);
}

llong get_pos(llong mid) {
    return mid / a + mid / b - mid / _lcm_a_b;
}

void process() {
    _lcm_a_b = (a*b) / __gcd(a, b);
    llong l = 1, r = 1e18, ans = -1;
    while (l <= r) {
        llong mid = (l+r) >> 1;
        if (get_pos(mid) >= n) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans;
}

int main() {

    enter();
    process();

    return 0;
}
    
