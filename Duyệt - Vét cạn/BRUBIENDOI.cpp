#include <iostream>
#include <algorithm>

using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    while (k--) {
        if (n % 10 != 0) --n;
        else n /= 10;
    }
    cout << n;
    return 0;
}
    
