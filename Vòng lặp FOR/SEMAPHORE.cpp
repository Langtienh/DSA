#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    for(int i=1, h = n; i <= n; --h, ++i, putchar('\n')) 
        for(int j=1; j<=h; ++j) cout << '*';
        
    return 0;
}
    
