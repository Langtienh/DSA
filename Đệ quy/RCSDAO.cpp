#include <bits/stdc++.h>

using namespace std;

long long sole(long long n ) {
    if (n < 10 && n % 2 == 1) return 1;
    if (n < 10 && n % 2 == 0) return 1;
    return sole(n) + sole(n / 10);
}

int main() {
    long long n;
    cin >> n;
    cout << sole(n);
    return 0;
}
    
