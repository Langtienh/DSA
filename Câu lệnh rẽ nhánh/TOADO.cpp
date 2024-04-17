#include <iostream>

using namespace std;

long long a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    if (a*a + b*b == c*c + d*d) cout << "BANG NHAU";
    else cout << ((a*a + b*b < c*c + d*d) ? "A" : "B");
    
    return 0;
}
    
