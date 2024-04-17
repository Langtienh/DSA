#include <iostream>

using namespace std;

long long n;

int main() {
    cin >> n;
    int m =  0;
    while (n > 0) m += n % 10, n /= 10;
    cout << m;
    return 0;
}
    
