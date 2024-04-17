#include<bits/stdc++.h>
#define ll long long
#define li long int
#define MaxN 100007

using namespace std;

ll f[MaxN],a[MaxN];
ll mm = 1e18;
li n,s,t,l[4],c[4],p[4];

void Nhap()
{
    cin >> l[1] >> l[2] >> l[3] >> c[1] >> c[2] >> c[3];
    cin >> n;
    cin >> s >> t;
    a[0]=0;
    for(li i=2; i<=n ; i++)
    {
        cin >> a[i];
    }
}

void Xuly()
{
    li i,j;
    for(i=1;i<=3;i++) p[i]=s;
    for(i=s+1;i<=t;i++)
    {
        f[i]=mm;
        for(j=3; j>=1; j--)
        {
            while(a[i]-a[p[j]]>l[j]) p[j]++;
            f[i]=min(f[i],f[p[j]]+c[j]);
            p[j-1]=p[j];
        }
    }
}

void Xuat()
{
    cout << f[t];
}

main()
{
    Nhap();
    Xuly();
    Xuat();
    return 0;
}
    
