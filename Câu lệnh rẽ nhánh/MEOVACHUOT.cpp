#include <iostream>
#include <algorithm>

using namespace std;
long long a, b, c;

int main() {
    scanf("%I64d%I64d%I64d", &a, &b, &c);
    if (abs(a-c) > abs(b-c)) { cout << "Cat_B";
    } else if (abs(a-c) < abs(b-c)) { cout << "Cat_A";
    } else cout << "Mouse_C";
}
    
