#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <queue>
#define llong long long

using namespace std;

priority_queue<llong, vector<llong>, greater<llong> > PQ;
llong res = 0;
int n;

int main() {
    scanf("%d", &n);
    while (n--) {
        int a; scanf("%d", &a);
        PQ.push(a);
    }
    while(PQ.size() > 1) {
        llong S = PQ.top(); PQ.pop();
        S += PQ.top(); PQ.pop();
        res += S; PQ.push(S);
    }
    cout << res;

    return 0;
}
    
