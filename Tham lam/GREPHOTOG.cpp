#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, d, a, b;

struct Data {
    int x, y, pos;
    
    bool operator < (const Data &other) const {
        return x*a + y*b < other.x*a + other.y*b;
    }
} P[100006];

int main() {
    scanf("%d%d", &n, &d);
    scanf("%d%d", &a, &b);
    for(int i=1; i<=n; ++i) scanf("%d%d", &P[i].x, &P[i].y), P[i].pos = i;
    sort(P+1, P+n+1);
    long long S = 0;
    vector<int> V;
    for(int i=1; i<=n; ++i) 
        if (S + P[i].x * a + P[i].y * b <= d) {
             V.push_back(P[i].pos);
             S += P[i].x * a + P[i].y * b;
        } else break;
    cout << V.size() << "\n";
    sort(V.begin(), V.end());
    for(vector<int>::iterator i = V.begin(); i!= V.end(); ++i) 
        cout << (*i) << " ";
    return 0;
}
    
