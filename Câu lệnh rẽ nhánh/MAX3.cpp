#include <iostream>

using namespace std;

long long a, b, c;

int main() {
    cin >> a >> b >> c;
    cout << "So lon nhat: " << max(max(a, b), c);
    
    return 0;
}
    
