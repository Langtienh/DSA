#include <iostream>

using namespace std;

long long sum = 0;
int n;

int main () {
    cin >> n;
    for(int i=1; i<=n; ++i)
    for(int j=1, a; j<=n; ++j) {
        cin >> a;
        if (i == j) sum += a;
    } 
    
    cout << sum;
    
    return 0;
}
    
