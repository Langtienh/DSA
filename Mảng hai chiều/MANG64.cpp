#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    for(int i=2; i<=2+n-1; ++i, putchar('\n')) 
        for(int j=i; j<=(i+n-1); ++j, putchar(' ')) cout << j; 
    return 0;
}
    
