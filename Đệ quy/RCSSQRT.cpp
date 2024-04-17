#include <iostream>
#include <algorithm>
#define ldouble long double

using namespace std;

int n;

int main() {
    cin >> n;
    (cout << fixed).precision(3);
    ldouble res = 0;
    for(int i=1; i<=n; ++i) res = sqrt(res + i);
    cout << res;
    
    return 0;
}
    
