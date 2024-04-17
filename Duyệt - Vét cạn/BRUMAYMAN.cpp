#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> test;
int num;

void back_track(int cnt) {
    for(int i=0; i<2; ++i) {
        num *= 10; num += ((i == 0) ? 6 : 8);
        if (cnt == 9) test.push_back(num);
        else back_track(cnt+1);
        num /= 10;
    }
}

bool check(int x) {
    for(int val : test)
        if (val > x) return false;
        else if (x % val == 0) return true;
    return false;
}

int main() {
    for(int i=9; i; --i) num = 0, back_track(i);
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        if (check(n)) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
    
