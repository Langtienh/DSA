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
    	if (a == k) res.push_back(i);
    }
    if (!res.size()) cout << "NO";
    else {
    	cout << res.size() << "\n";
    	for (int i=0; i<(int) res.size(); ++i) cout << res[i] << " ";
    }
    
    return 0;
}
    
