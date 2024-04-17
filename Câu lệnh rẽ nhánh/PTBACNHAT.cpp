#include <iostream>

using namespace std;

long double a, b, c;

int main() {
    cin >> a >> b;
    (cout << fixed).precision(2);
    if(a == 0) {
        if (b == 0) cout << "VO SO NGHIEM";
        else cout << "VO NGHIEM";
    } else cout << "PT CO NGHIEM\nX = " << -b/a;
    
    return 0;
}
    
