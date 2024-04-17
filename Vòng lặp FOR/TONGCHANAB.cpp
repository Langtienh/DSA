#include <iostream>

using namespace std;

int main() {
    int l, r; cin >> l >> r;
    l = ((l+1) >> 1) << 1;
    r = (r >> 1) << 1;
    cout << (((1LL*r+l)*(((1LL*r - l) >> 1) + 1)) >> 1);
    
    return 0;
}
    
