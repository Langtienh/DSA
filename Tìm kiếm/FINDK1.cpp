#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, a, k;
    vector<int> res;
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; ++i) {
    	scanf("%d", &a);
    	if (a == k) {
    	    cout << "YES";
    	    return 0;
    	}
    }
    cout << "NO";
    
    return 0;
}
    
