#include <iostream>

using namespace std;

bool check(int n) {
    long long sum = 0;
    for(int i=2; i*i <= n; ++i)
        if (n % i == 0) {
            sum += i;
            if (i * i < n) sum += (n / i);
        }
    if (sum == 1LL*n-1) return true;
    return false;
}

int main() {
    int n; cin >> n;
    if (check(n)) cout << "YES";
    else cout << "NO";
    
    return 0;
}
    
