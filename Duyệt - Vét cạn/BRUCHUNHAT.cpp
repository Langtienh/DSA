#include <iostream>

using namespace std;

long long a, b;

int main()
{
    cin >> a >> b;
    (cout << fixed).precision(1);
    long long num = min(b, a/2);
    cout << 1.*a*b / 2 << "\n";
    cout << (1.*a*b + num*num - a*num) / 2.0;
    return 0;
}
    
