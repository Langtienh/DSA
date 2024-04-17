#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int> > ans;
char S1[56], S2[56];
int n;

void process() {
    for(int i=0; i<n; ++i)
        if (S1[i] != S2[i]) {
            int j = i+1;
            while (j < n) {
                if (S1[j] == S2[j]);
                else if (S1[i] == S1[j]) {
                    S1[j] = S2[i]; S2[i] = S1[i];
                    ans.push_back(make_pair(j+1, i+1));
                    break;
                } else if (S1[i] == S2[j]) {
                    S2[j] = S1[j];
                    S1[j] = S2[i];
                    S2[i] = S1[i];
                    ans.push_back(make_pair(j+1, j+1));
                    ans.push_back(make_pair(j+1, i+1));
                    break;
                }
                ++j;
            }
            if (j == n) {
                cout << "No\n";
                return;
            }
        }
    if ((int) ans.size() > 2*n) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    cout << ans.size() << "\n";
    for(pair<int, int> e : ans) cout << e.first << " " << e.second << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        scanf("%s", S1);
        scanf("%s", S2);
        ans.clear();
        process();
    }
    return 0;
}
    
