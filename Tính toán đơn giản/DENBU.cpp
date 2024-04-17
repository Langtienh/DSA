#include <iostream>

using namespace std;

long long a, b, c, m, n, k;

int main() {
    cin >> a >> b >> c >> m >> n >> k;
    cout << a*m + b*k + c*(n-m-k);
    return 0;
}
    
