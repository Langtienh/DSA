#include <iostream>

using namespace std;

int p;

int main() {
    int n; cin >> n;
    for(int i=1, a; i<=n; ++i) {
        cin >> a;
        if (a == 1) p++; else p--;
    }
    
    cout << abs(p);
    
    return 0;
}
    
