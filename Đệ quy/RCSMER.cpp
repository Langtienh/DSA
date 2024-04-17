#include <iostream>
#include <string>

using namespace std;

string s,t,miin = "999999999999999999",maax = "0";

void back_track(int x,int y,string res){
    if(res.length() == s.length() + t.length()){
        miin = min (res,miin);
        maax = max (res,maax);
    }
    if(x<(int) s.length()) back_track(x+1,y,res + s[x]);
    if(y<(int) t.length()) back_track(x,y+1,res + t[y]);
}

int main (){
    cin >> s >> t;
    back_track(0,0,"");
    cout << miin << "\n" << maax ;
}
    
