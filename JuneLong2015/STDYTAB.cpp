#include <bits/stdc++.h>

using namespace std;

#define MAX 4005
#define MOD 1000000000
typedef long long ll;

ll C[MAX][MAX], dp[MAX][MAX];
int t, n, m;
void init()
{
    C[0][0]=1;
    for(int i=1;i<MAX;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
        }
    }
}


ll solve(int i, int x)
{
    if(i==n+1)
        return 1;
    if(x>m)
        return 0;
    if(dp[i][x]==0)
        dp[i][x] = (((solve(i+1, x)*C[x+m-1][m-1])%MOD)+solve(i, x+1))%MOD;
    //cout<<"i: "<<i<<", x: "<<x<<", dp[][]:"<<dp[i][x]<<endl;
    return dp[i][x];
}

void solve2()
{
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        ll s=0;
        for(int j=0;j<=m;j++)
        {
            s+=dp[i-1][j];
            if(s>=MOD)
                s-=MOD;
            dp[i][j]=(1LL*s*C[j+m-1][m-1])%MOD;
        }
    }
    ll ans=0;
    for(int i=0;i<=m;i++)
    {
        ans+=dp[n][i];
        if(ans>=MOD)
            ans-=MOD;
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    printf("%lld\n", ans);
}

int main()
{
    init();
    scanf("%d", &t);
    while(t--)
    {
        //memset(dp, 0,sizeof(dp));
        scanf("%d %d", &n, &m);
        for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j] = 0 ;
        //printf("%lld\n", solve(1, 0));
        solve2();
    }
    return 0;
}
