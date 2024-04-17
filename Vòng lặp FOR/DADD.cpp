#include <iostream>

using namespace std;

int neg, pos;

int main() {
    int n; scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        long long a; scanf("%I64d", &a);
        if(a < 0) ++neg; else if (a>0) ++pos;
    }
    cout << "SO DUONG: " << pos << "\nSO AM: " << neg;
    
    return 0;
}
    
