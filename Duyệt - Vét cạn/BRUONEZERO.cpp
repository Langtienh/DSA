#include <iostream>
#include <algorithm>
#include <climits>
#define ull unsigned long long

using namespace std;

bool next_num(ull &n) {
    if (n == ULLONG_MAX - 1) return false;
    if ((n & 1) == 0) {
        ull num = n >> 1;
        ull base = 1;
        if (n == 0) base = 2;
        while (n > 0) base <<= 1, n >>= 1;
        n = num + base;
        return true;
    } else {
        ull base = 0;
        int l = 0;
        while (n > 0) {
            if ((n & 1) == 0) {
                base >>= 1;
                ++n;
                while (l--) n <<= 1;
                n += base;
                return true;
            } else base <<= 1, base += 1, ++l, n >>= 1;
        }
    }
    return false;
}

ull n;

int main() {
    int res = 0;
    ull m = 0;
    cin >> n;
    while (next_num(m)) {
        if ((ull) m > n) break;
        ++res;
    }
    cout << res;
    return 0;
}
    
