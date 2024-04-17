#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    int res = 0;
    while (n < m) {
        ++res;
        if (n % 10 < 5) n += (n/10);
        else n += (n/10+1); 
    }
    cout << res;
    
    return 0;
}
    
