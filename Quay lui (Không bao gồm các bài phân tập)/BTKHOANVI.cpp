#include <iostream>
#include <algorithm>

using namespace std;

int n, x[12];

int main() {
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cout << i << " ";
        x[i] = i;
    } putchar('\n');
    while (next_permutation(x+1, x+n+1)) {
         for(int i=1; i<=n; ++i) cout << x[i] << " ";
    	 putchar('\n');
    }
    
    return 0;
}
    
