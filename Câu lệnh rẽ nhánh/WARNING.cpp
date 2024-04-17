#include <iostream>

using namespace std;

int main() {
    long long a, b, k, t;
    cin >> a >> b >> k >> t;
    a *= 100, b *= 100;
    if (a*b*k >= t*3000000) cout << "YES";
    else cout << "WARNING";
    
    return 0;
}
    
