#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, c;

int main() {
     cin >> a >> b >> c;
     if (a == b || a == c || b == c) cout << "LA TAM GIAC CAN";
     else cout << "KHONG PHAI TAM GIAC CAN";
     
     return 0;
}
    
