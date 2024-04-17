#include <iostream>

using namespace std;

int a, b;

int main() {
    scanf("%d%d", &a, &b);
    int res = -1;
    while (a <= b) {
    	++res;
    	a <<= 1;
    }
    cout << res;
}
    
