#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    cout << ((3LL*n*(n-1)) >> 1) + n;
    putchar('\n');
    for(int i=1, a=1; i<=n; ++i) {
        cout << a << " ";
        a += 3;
    }
    
    return 0;
}
    
