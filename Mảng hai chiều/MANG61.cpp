#include <iostream>

using namespace std;

int main() {
    int n, m, res = 0;
    cin>> n >> m;
    for(int i=1, a; i<=n*m; ++i) {
        cin >> a;
        if (a % 3 == 0) ++res;
    }
    cout << res;
    
    return 0;
}
    
