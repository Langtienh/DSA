#include <iostream>

using namespace std;

long long x, y, z, t;

int main() {
    cin >> x >> y >> z >> t;
    cout << z*x*2*39 + z*y*2*39 + y*(t-z)*39;
    
    return 0;
}
    
