#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c = a*b / __gcd(a, b);
    cout << c << '\n';
    cout << "An: " << c/a << "\n";
    cout << "Bach: " << c/b; 
}
    
