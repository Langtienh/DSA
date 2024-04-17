#include <iostream>
#include <algorithm>

using namespace std;

long long a, b;

int main() {
   scanf("%I64d%I64d", &a, &b);
   long long c = __gcd(a, b);
   cout << "So to: " << c << "\n";
   cout << "So nam moi to: " << a/c << "\n";
   cout << "So nu moi to: " << b/c;
}
    
