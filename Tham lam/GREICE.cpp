#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int a[10], b[10];
bool avail[10];

string A, B;

void init_A() {
    int n = A.length();
    for(int i=0; i<n; ++i) {
        int num = A[i] - '0';
        if (num == 6 || num == 9) {
            avail[6] = true;
            ++a[6];
        } else if (num == 2 || num == 5) {
            avail[2] = true;
            ++a[2];
        } else {
            avail[num] = true;
            ++a[num];
        }
    }
}

void check_B() {
    int n = B.length();
    for(int i=0; i<n; ++i) {
        int num = B[i] - '0';
        if (num == 6 || num == 9) ++b[6];
        else if (num == 2 || num == 5) ++b[2];
        else ++b[num];
    }
    int mmin = n;
    for(int i=0; i<9; ++i)
        if (avail[i]) mmin = min(mmin, b[i] / a[i]);
    cout << mmin;
}
int main() {
    cin >> A;
    cin >> B;
    init_A();
    check_B();
    return 0;
}
    
