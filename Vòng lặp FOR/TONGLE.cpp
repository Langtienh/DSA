#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    if (n & 1) ++n;
    cout << ((1LL*n)*(1LL*n) >> 2);
    
    return 0;
}
    
