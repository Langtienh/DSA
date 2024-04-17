#include <iostream>

using namespace std;

long long a, b;

int main() {
   scanf("%I64d%I64d", &a, &b);
   a = (a + 5) / 6 * 6;
   b = b - (b % 6);
   cout << (b - a) / 6 + 1; 
}
    
