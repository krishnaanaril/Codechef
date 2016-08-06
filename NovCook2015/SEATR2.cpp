#include <bits/stdc++.h>

#define MAXN 501
#define MAXM 20001
#define MOD 1000000007

using namespace std;

int dp[MAXN][MAXM];
vector<int> tree[MAXN];
int t, n, m, u, v, ans;

void dfs(int u, int p=-1)
{
    int sz = tree[u].size(), i, j, v;
    for(i=1;i<=m;i++)
        dp[u][i]=1;
    for(i=0;i<sz;i++)
        if(tree[u][i]!=p)
            dfs(tree[u][i], u);
            
    for(j=1;j<=m;j++)
    {
        for(i=0;i<sz;i++)
        {
            if(tree[u][i]!=p)
            {
                dp[u][j] = 1LL*dp[u][j]*dp[tree[u][i]][j]%MOD;
            }
        }
    }
    
    ans=0;
    for(i=1;i<=m;i++)
    {
        ans += dp[u][i];
        if( ans >= MOD ) ans -= MOD;
        j=i, v=0;
        while(j<=m)
        {
            v += dp[u][j];
            if( v >= MOD ) v -= MOD;
            j+=i;
        }
        dp[u][i] = v;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>t;
    int i, j;
    //scanf("%d", &t);
    while(t--)
    {
        cin>>n>>m;
        //scanf("%d%d", &n, &m);
        for(i=1;i<=n;i++)
        {
            tree[i].clear();
            for(j=1;j<=m;j++)
                dp[i][j]=0;
        }
        for(i=0;i<n-1;i++)
        {
            cin>>u>>v;
            //scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(1, -1);
        cout<<ans<<endl;
        //printf("%d\n", ans);
    }
    return 0;
}
