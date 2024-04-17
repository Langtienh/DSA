#include <iostream>
#include <algorithm>

using namespace std;

long double a, b, alpha;
const long double Pi = 3.141592653589793238462643383279502884L;

int main() {
    cin >> b >> a >> alpha;
    long double c = (1.0L*a - b) / 2.0L;
    long double h = c * tan(alpha * Pi / 180.0L);
    long double j = sqrt(c*c + h*h);
    (cout << fixed).precision(4);
    cout << a+b+2*j << "\n" << (a+b)*h/2.0L;
    return 0;
}
    
