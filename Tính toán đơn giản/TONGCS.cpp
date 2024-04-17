#include <iostream>

using namespace std;

int a, b;

int main() {
    cin >> a;
    int res = 0;
    while (a > 0) res += a%10, a /= 10;
    cout << res;
    return 0;
}
    
