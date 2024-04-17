#include <iostream>
#include <string>

using namespace std;

string A, B;

int main() {
     cin >> A >> B;
     while (A.length() < B.length()) A = '0' + A;
     while (A.length() > B.length()) B = '0' + B;
     string C = ""; int rem = 0;
     for(int i=A.length()-1; i>=0; --i) {
          int x =  (A[i] - '0') + (B[i] - '0') + rem;
          rem = x/10;
          C = char(x%10+48) + C;
     }
     if (rem) C = char(rem+48) + C;
     cout << C;
}
    
