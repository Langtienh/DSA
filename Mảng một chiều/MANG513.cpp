#include <iostream>

using namespace std;

int a[1000006];

int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) {
        int b; scanf("%d", &b);
        cout << a[i] << " " << b << " ";
    }
    
    return 0;
}
    
