#include <iostream>
#include <algorithm>

using namespace std;

int M[3][2006][2006];
const int dh[3] = {3, -5, -20};
const int da[3] = {2, -10, 5};

int get_res(int H, int A, int kind) {
    if (H <= 0 || A <= 0) return 0;
    if (M[kind][H][A]) return M[kind][H][A];
    for(int i=0; i<=2; ++i)
        if (i != kind) M[kind][H][A] = max(M[kind][H][A], get_res(H+dh[i], A+da[i], i) + 1);
    return M[kind][H][A];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int H, A; scanf("%d%d", &H, &A);
        int mmax = 0;
        for(int i=0; i<3; ++i) mmax = max(mmax, get_res(H+dh[i], A+da[i], i));
        cout << mmax << "\n";
    }
    return 0;
}
    
