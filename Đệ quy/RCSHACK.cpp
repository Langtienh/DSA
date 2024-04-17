#include <iostream>
#define llong long long

using namespace std;

bool check(llong n) {
    int num = 0, num1 = 0;
    while (n % 10 == 0) n /= 10, ++num;
    while (n % 2 == 0) n /= 2, ++num1;
    return n == 1 && num1 <= num;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        llong n; scanf("%I64d", &n);
        if (check(n)) cout << "Yes\n";
        else cout << "No\n";
    }
}
    
