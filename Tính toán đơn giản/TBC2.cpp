#include <iostream>

using namespace std;

long double a, s;

int main() {
    s = 0;
    cin >> a; s+=a;
    cin >> a; s+=a;
    cin >> a; s+=a;
    cin >> a; s+=a;
    (cout << fixed).precision(2);
    cout << s / 4.0L;
}
    
