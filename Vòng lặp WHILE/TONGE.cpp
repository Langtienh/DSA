#include <iostream>
#include <algorithm>
#define ldouble long double
#define llong long long

using namespace std;

ldouble n;

int main() {
    cin >> n;

    ldouble e = 0; llong i = 1, h = 1;
    while (e <= n) {
        e += 1.0L*1 / (1.0L*i);
        h += 2; i += h;
    }

    (cout << fixed).precision(9);
    cout << e;

    return 0;
}
    
