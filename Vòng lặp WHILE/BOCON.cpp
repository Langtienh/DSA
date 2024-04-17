#include <iostream>

using namespace std;

int main() {
    long long b, c;
    cin >> b >> c;
    if (b - c < c) cout << "KHONG BAO GIO GAP DOI";
    else cout << b - 2*c;
    
    return 0;
}
    
