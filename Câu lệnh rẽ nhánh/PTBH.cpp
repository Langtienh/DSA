#include <iostream>
#include <algorithm>

using namespace std;

int main() {
   long long a, b, c; cin >> a >> b >> c;
   (cout << fixed).precision(2);
   long long delta = b*b - 4*a*c;
   if (delta == 0) {
      cout << "PT CO NGHIEM KEP\nX = " << (-1.0L*b)/(2.0L*a);
   } else if (delta > 0) {
      cout << "PT CO HAI NGHIEM\nX1 = " << (-1.0L*b + sqrt(1.0L*delta)) / (2.0L*a) << "\nX2 = " << (-1.0L*b - sqrt(1.0L*delta)) / (2.0L*a);
   } else cout << "VO NGHIEM";
}
    
