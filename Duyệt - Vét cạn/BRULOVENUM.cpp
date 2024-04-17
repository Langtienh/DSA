#include <iostream>

using namespace std;

int main() {
    int n, pos = -1;
    cin >> n;
    for(int i=0; i*7 <= n; ++i)
        if ((n - i*7) % 4 == 0) pos = i;
    if (pos == -1) cout << -1;
    else {
        for(int i=1; i*4 + pos*7 <=n; ++i) cout << 4;
        while (pos--) cout << 7;
    }
    return 0;
}
    
