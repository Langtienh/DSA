#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    int maxn=200004,n,res=1,pos=1;
    int a[maxn],increase[maxn],trace[maxn],dp[maxn];
    cin >>n;
    for (int i=1;i<=n;i++) cin >>a[i];
    dp[res]=a[1];
    increase[1]=1;
    for (int i=2;i<=n;i++)
        if (a[i]>dp[res])
        {
            res++;
            dp[res]=a[i];
            increase[res]=i;
            trace[i] = increase[res-1];
            pos = i;
        }
        else
        {
            int first=1,finish=res,location=0;
            while (first<=finish)
            {
                int mid=(first+finish)/2;
                if (dp[mid]<a[i])
                {
                    location=mid;
                    first=mid+1;
                }
                else finish=mid-1;
            }
            trace[i] = increase[location];
            dp[location+1]=a[i];
            increase[location+1]=i;
        }
        cout <<res<<endl;
        vector<int> V;
        while (pos != 0) V.push_back(pos), pos = trace[pos];
        reverse(V.begin(), V.end());
        for(vector<int>::iterator i = V.begin(); i != V.end(); ++i) cout << (*i) << " ";
}
    
