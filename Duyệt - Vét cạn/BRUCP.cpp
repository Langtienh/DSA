#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    for(int i=1; i<=n; ++i)
    for(int j=i; j<=n; ++j) {
        int k = sqrt(i*i + j*j);
        if (k*k == i*i + j*j) cout << i << " " << j << "\n";
    }
    return 0;
}
    
