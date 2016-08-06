#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MAX 5000005
#define INF (1<<20)

typedef long long ll;

bool flag;
ll n, k, m, l, r, c;
ll arr[N], dat[N], cost[N], dp[100001][505];
ll tree[MAX], lazy[MAX];
ll sum=0;


void build(ll node, ll a, ll b)
{
    if(a>b)
        return;
    if(a==b)
    {
        //cout<<node<<" -> "<<a<<" -> "<<arr[a]<<endl;
        tree[node]=arr[a];
        return;
    }
    build(node*2, a, (a+b)/2);
    build(node*2+1, ((a+b)/2)+1, b);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

void update(ll node, ll a, ll b, ll i, ll j, ll val)
{
    if(lazy[node]!=INF)
    {
        tree[node]=min(tree[node],lazy[node]);
        if(a!=b)
            lazy[node*2]=min(lazy[node*2], lazy[node]),
            lazy[node*2+1]=min(lazy[node*2+1], lazy[node]);
    }
    if(a>b || a>j || b<i)
        return;
    if(a>=i && b<=j)
    {
        tree[node]=min(tree[node],val);
        if(a!=b)
            lazy[node*2]=min(lazy[node*2],val),
            lazy[node*2+1]=min(lazy[node*2+1],val);
        return;
    }
    update(node*2, a, (a+b)/2, i, j, val);
    update(node*2+1, ((a+b)/2)+1, b, i, j, val);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

ll query(ll node, ll a, ll b, ll i, ll j)
{    
    if(a>b || a>j || b<i)
    {
        return INF;
    }
    if(lazy[node]!=INF)
    {
        tree[node]=min(tree[node], lazy[node]);
        if(a!=b)
            lazy[node*2]=min(lazy[node*2], lazy[node]),
            lazy[node*2+1]=min(lazy[node*2+1], lazy[node]);
        lazy[node]=INF;
    }
    if(a>=i && b<=j)
    {
        return tree[node];
    }
    int q1=query(node*2, a, (a+b)/2, i, j);
    int q2=query(node*2+1, ((a+b)/2)+1, b, i, j);
    return min(q1, q2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        //memset(dp, 0, sizeof(dp));
        sum=0;
        fill(lazy, lazy+MAX, INF);
        flag=false;
        cin>>n>>k>>m;
        for(int i=0;i<n;i++)
        {
            arr[i]=INF;
            cin>>dat[i];
            sum+=dat[i];
            if(dat[i]<0)
                flag=true;
            dat[i]*=-1;
        }
        build(1, 0, n-1);
        for(int i=0;i<m;i++)
        {
            cin>>l>>r>>c;
            l--; r--;
            //cout<<l<<" : "<<r<<" : "<<c<<endl;
            update(1, 0, n-1, l, r, c);
            /*for(int i=0;i<n;i++)
            {
                cout<<query(1, 0, n-1, i, i)<<" ";
            }
            cout<<endl<<"Tree: ";
            for(int i=0;i<15;i++)
            {
                cout<<tree[i]<<" ";
            }
            cout<<endl;*/
        }
        if(!flag)
        {
            cout<<sum<<endl;
        }
        else
        {            
            for(int i=0;i<n;i++)
            {
                cost[i]=query(1, 0, n-1, i, i);
                //cout<<cost[i]<<" ";
            }
            //cout<<endl;
            /*for(int i=0;i<n;i++)
            {
                cout<<dat[i]<<" ";
            }
            cout<<endl;*/
            for (int i = 0; i <= n; i++)
            {
                for (int w = 0; w <= k; w++)
                {
                    if (i==0 || w==0)
                        dp[i][w] = 0;
                    else if (cost[i-1] <= w)
                          dp[i][w] = max(dat[i-1] + dp[i-1][w-cost[i-1]],  dp[i-1][w]);
                    else
                          dp[i][w] = dp[i-1][w];
                }
            }
            cout<<(sum+dp[n][k])<<endl;
        }
    }
    return 0;
}
