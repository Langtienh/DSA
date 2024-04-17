#include <iostream>

using namespace std;

int main() {
    int res = 0;
    long long n;
    cin >> n;
    while (n > 0) res += n%10, n/=10;
    if (res % 10 == 9) cout << "YES";
    else cout << "NO";
    
    return 0;
}
    
