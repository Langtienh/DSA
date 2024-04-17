#include <iostream>

using namespace std;

long long n;

int main() {
    cin >> n;
    while (true) {
        int num = 0;
        if (n == 0) break;
        long long m = 0;
        while (n > 0) ++num, m += n % 10, n /= 10;
        n = m;
        if (num == 1) break;
    }
    cout << n;
    return 0;
}
    
