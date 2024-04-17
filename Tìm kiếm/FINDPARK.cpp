#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, r, l=1;
llong c1, c2;

llong cost(int mid) {
    int num = n / mid, mod = n % mid;
    return c1*mid + mod*c2*num*num + (mid - mod)*c2*(num-1)*(num-1);
}

int main() {
    cin >> n >> r >> c1 >> c2;
    while (l + 3 <= r) {
        int mid1 = l + (r-l) / 3;
        int mid2 = r - (r-l) / 3;
        if (cost(mid1) < cost(mid2)) r = mid2;
        else if (cost(mid1) > cost(mid2)) l = mid1;
        else l = mid1, r = mid2;
    }
    for(int i=l+1; i<=r; ++i)
        if (cost(i) < cost(l)) l = i;
    cout << cost(l);
    return 0;
}
    
