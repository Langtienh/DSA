#include <iostream>
#include <algorithm>

using namespace std;

long double a, b, c;

int main() {
    cin >> a >> b >> c;
    long double n = (a+b+c) / 2.0L;
    (cout << fixed).precision(2);
    cout << sqrt(n*(n-a)*(n-b)*(n-c));
    return 0;
}
    
