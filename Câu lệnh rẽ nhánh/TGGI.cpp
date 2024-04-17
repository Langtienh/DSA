#include <iostream>
#include <algorithm>

using namespace std;

long double a[4];

bool check_tri(long double a, long double b, long double c) {
    return a+b>c && abs(a-b)<c && a+c>b && abs(a-c)<b && b+c>a && abs(b-c)<a;
}

int main() {
    cin >> a[1] >> a[2] >> a[3];
    if (!check_tri(a[1], a[2], a[3])) cout << "KHONGPHAITAMGIAC";
    else {
        sort(a+1, a+4);
        bool d1 = false, d2 = false;
        if(a[1] == a[2] && a[2] == a[3]) cout << "DEU";
        else {
            if (abs(a[3]*a[3] - a[2]*a[2] - a[1]*a[1]) < 1e-6) d1 = true;
            if (abs(a[1] - a[2]) < 1e-6 || abs(a[2] - a[3]) < 1e-6) d2 = true;
            if (d1 && d2) cout << "VUONG CAN";
            else if (d1) cout << "VUONG";
            else if (d2) cout << "CAN";
            else cout << "THUONG";
        }
    }

    return 0;
}
    
