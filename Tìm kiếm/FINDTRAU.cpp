#include <iostream>
#define llong long long
#define ldouble long double

using namespace std;

ldouble u1, v1, u2, v2;

int main() {
    cin >> u1 >> v1;
    cin >> u2 >> v2;
    if (v1 * v2 > 0) v1 = -v1;
    ldouble P1 = v2 - v1;
    ldouble P2 = u1 - u2;
    ldouble P3 = -(P1*u1 + P2*v1);
    (cout << fixed).precision(5);
    ldouble res = 0;
    if (P1 != 0.0L) res = -1.0L*P3 / (1.0L*P1); else res = (1.0L*u1 + v2) / 2.0L;
    cout << res;
}
    
