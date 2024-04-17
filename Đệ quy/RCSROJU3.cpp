#include <bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char A[1005][1005];
pair<int, int> pos, trace[1005][1005];
string str;
long long B[1001][1001],m,n,a,b,c,d,best = 1e9;
typedef pair<int , int>ii;
vector<pair<int, int> > V;
bool ok = false;
void romeo(long long x,long long y,long long dem)
{
    B[x][y]=2;
    if(x==c && y==d)
    {
        B[x][y] = 1;
        if (dem < best) {
            best = dem;
            pos = make_pair(x, y); ok = true;
            V.clear();
            while (pos.first > 0) {
                V.push_back(pos);
                pos = trace[pos.first][pos.second];
            }
        }
        return;
    }
    for(int i=0;i<4;i++)
    {
        long long u=dx[i]+x;
        long long v=dy[i]+y;
        if(B[u][v]==1)
        {
            trace[u][v] =make_pair(x, y);
            if (dem < best) romeo(u,v,dem+1);
            B[u][v] = 1;
        }
    }
}
int main()
{
    cin>>m>>n;
    memset(B,0,sizeof(B));
    for(int i=1;i<=m;i++)
    {
        cin>>str;
        for(int j=1;j<=n;j++)
        {
            A[i][j]=str[j-1];
            if(A[i][j]=='R')
            {
                a=i;
                b=j;
                B[i][j]=1;
            }
            if(A[i][j]=='J')
            {
                c=i;
                d=j;
                B[i][j]=1;
            }
            if(A[i][j]=='o')
            {
                B[i][j]=1;
            }
        }
    }
    romeo(a,b,0);
    if (ok) {
        cout << "YES\n";
        cout << best + 1 << "\n";
        for(vector<pair<int, int> >::reverse_iterator i = V.rbegin(); i != V.rend(); ++i)
            cout << (*i).first << " " << (*i).second << "\n";
    } else cout << "NO";
    return 0;

}
    
