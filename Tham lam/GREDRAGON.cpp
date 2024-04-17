#include <iostream>
#include <algorithm>
#define fname "GREDRAGON"

struct Data {
    int x, y;

    bool operator < (const Data &other) const {
        return x < other.x || (x == other.x && y > other.y);
    }
} P[100006];

using namespace std;

int s, n;

void enter() {
    scanf("%d%d", &s, &n);
    for(int i=1; i<=n; ++i)
        scanf("%d%d", &P[i].x, &P[i].y);
}

void check() {
    sort(P+1, P+n+1);
    for(int i=1; i<=n; ++i)
        if (s <= P[i].x) {
            cout << "NO";
            return;
        } else s += P[i].y;
    cout << "YES";
}

int main() {

    enter();
    check();

    return 0;
}
    
