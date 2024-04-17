#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong n;

int main() {
    cin >> n;
    int res = 1;
    while (n > 1) {
        if (n & 1) n *= 3, ++n;
        else n >>= 1;
        ++res;
    }
    cout << res;
    return 0;
}
    
