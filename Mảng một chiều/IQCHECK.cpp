#include <iostream>
#include <vector>

using namespace std;

vector<int> A[2];

int main() {
    int n; scanf("%d", &n);
    for(int i=1, a; i<=n; ++i) {
        scanf("%d", &a);
        A[a & 1].push_back(a);
    }
    if ((int) A[0].size() == 1) cout << A[0][0];
    else cout << A[1][0];
    
    return 0;
}
    
