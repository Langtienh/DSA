#include <iostream>

using namespace std;

int main() {
    for (int i=1; i<=3; ++i) {
    	long long a; cin >> a;
    	if (a < 0) cout << a*a << " ";
    	else cout << a*a*a << " ";
    }
    
    return 0;
}
    
