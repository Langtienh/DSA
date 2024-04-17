#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    if (n & 1) {cout << '7'; n-=3;}
    for(int i=1; i*2 <=n; ++i) cout << '1';
    return 0;
}
    
