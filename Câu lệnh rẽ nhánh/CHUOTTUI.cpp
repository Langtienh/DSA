#include <iostream>

using namespace std;

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c) swap(a, c), swap(b, d);
    if (b > d) {
        if ((c - a) % (b - d) == 0) cout << "YES";
        else cout << "NO";
    }
    else if (a == c && b == d) cout << "YES";
    else cout << "NO";

    return 0;
}
    
