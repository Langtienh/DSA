#include <iostream>
#define llong long long

using namespace std;

void next_num(llong &n) {
    if (n < 19) {
        n = 19;
        return;
    }
    llong m = n; int l = 0, sum = 0;
    while (m % 10 == 0) m /= 10, ++l;
    m /= 10; ++m;
    while (l > 0) m *= 10, --l;
    n = m;
    while (m > 0) sum += (m % 10), m /= 10;
    n *= 10, n += 10 - sum;
}

int main() {
    int k; cin >> k;
    llong n = 0;
    while (k--) next_num(n);
    cout << n;
    return 0;
}
    
