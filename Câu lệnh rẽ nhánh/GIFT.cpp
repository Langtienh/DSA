#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        unsigned long long a, b, u, v, t;
        cin >> a >> b >> u >> v >> t;
        if (u > v) u = min(u, v+t); else v = min(v, u+t);
        cout << a*u + b*v; putchar('\n');
    }
}
    
