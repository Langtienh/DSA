#include <iostream>
#include <vector>

using namespace std;

int a, b;
vector<int> V;

int main() {
    cin >> a >> b;
    while (b > a) {
        V.push_back(b);
        if (b % 10 == 1) b /= 10;
        else if (b % 2 == 0) b /= 2;
        else {
            cout << "NO";
            return 0;
        }
    }
    if (b < a) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    V.push_back(a);
    cout << V.size() << "\n";
    for(int i=V.size() - 1; i >= 0; --i) cout << V[i] << " ";
    return 0;
}
    
