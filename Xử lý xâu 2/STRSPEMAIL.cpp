#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S;
vector<string> S1;
int n;

int main() {
    cin >> S; n = S.length(); S.push_back('*');
    string tmp = "";
    for(int i=0; i<n; ++i)
        if (S[i] == '@') {
            if (i == n-1 || (int) tmp.size() == 0) {
                cout << "LAMSAOBAYGIO";
                return 0;
            } else {
                if (S[i+1] == '@') {
                    cout << "LAMSAOBAYGIO";
                    return 0;
                }
                tmp = tmp + S[i];
                ++i; bool ok = false;
                while (i < n && S[i + 1] != '@') tmp = tmp + S[i++], ok = true;
                if (!ok) {
                    cout << "LAMSAOBAYGIO";
                    return 0;
                }
                S1.push_back(tmp); S1.push_back(",");
                tmp = "";
                --i;
            }
        } else tmp = tmp + S[i];
    if (S1.size() == 0) {
        cout << "LAMSAOBAYGIO";
        return 0;
    }
    S1.pop_back();
    for(string e : S1) cout << e;
    return 0;
}
    
