#include <iostream>

using namespace std;

int main() {
    int digit;
    int n;
    cin >> n;
    while (n--) {
        long long m; cin >> m; 
        long long m1 = m;
        digit = 0;
        if (m == 0) digit = 1;
    	while (m > 0) digit += m%10, m/=10;
    	cout << m1 << " " << digit << "\n";
    }
    
    return 0;
}
    
