#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int res = 0;
    while (true) {
        if (n < 10) break;
        res += 10;
        n -= 7;
    }
    cout << res + n;
    
    return 0;
}
    
