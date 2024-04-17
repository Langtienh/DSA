#include <iostream>

using namespace std;

int pos = 0;

int main() {
    int n; scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        long long a; scanf("%I64d", &a);
        if (a % 5 == 0 && a > 0) ++pos;
    }
    cout << pos;
    
    return 0;
}
    
