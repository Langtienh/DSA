#include <iostream>
#include <algorithm>

using namespace std;

long long n;

void process() {
    long long res = 0;
    int g = 0;
    for(int i=1; 1LL*i*i <= n; ++i)
        if (n % i == 0) {
            res += i; ++g;
            if (1LL*i*i < n) res += (n / i), ++g;
        }
    cout << n << " co " << g << " uoc. Tong uoc la: " << res << "\n";
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%I64d", &n);
        process();
    }
    return 0;
}
    
