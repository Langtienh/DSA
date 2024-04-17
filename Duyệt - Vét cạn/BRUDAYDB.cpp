#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> res;

bool check(int x) {
    for(int i=2; i*i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

bool check1(int x) {
    for(int val : res)
        if (val % x == 0) return true;
    return false;
}

int main() {
    cin >> n;
    res.push_back(n);
    for(int i=n-1; i>0; --i)
        if (check(i) || check1(i)) res.push_back(i);
    cout << res.size() << "\n";
    for(int val : res) cout << val << " ";

    return 0;
}
    
