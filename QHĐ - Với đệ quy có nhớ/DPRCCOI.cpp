#include <iostream>
#include <algorithm>
#include <map>
#define llong long long

using namespace std;

map<int, llong> M;

llong get_res(int x) {
    if (M.count(x)) return M[x];
    return M[x] = get_res(x/2) + get_res(x/3) + get_res(x/4);
}

void init() {
    for(int i=0; i<=11; ++i) M.insert(make_pair(i, 1LL*i));
}

int main() {
    init();
    int n;
    while (scanf("%d", &n) != -1) cout << get_res(n) << "\n";
    return 0;
}
    
