#include <iostream>
#include <algorithm>

using namespace std;

long long a[4];

int main() {
    cin >> a[1] >> a[2] >> a[3];
    sort(a+1, a+4);
    if (a[3]*a[3] == a[2]*a[2] + a[1]*a[1]) cout << "Ba so da nhap la bo so Pi-ta-go";
    else cout << "Ba so da nhap khong la bo so Pi-ta-go";
    
    return 0;
}
    
