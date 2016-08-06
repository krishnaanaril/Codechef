#include <bits/stdc++.h>

using namespace std;

#define MAX 100005
#define INF (1<<20)
#define gc getchar_unlocked

typedef long long ll;
typedef pair<int, int> pii;

bool flag;
int t, n, k, m, l, r, c;
ll dat[MAX], cost[MAX], dp[MAX][501];
ll sum;
vector<int> L[MAX], R[MAX];
set<pii> iset;

struct meths
{
    int l, r, c;
};

int read_int(int &x)
{
	register int c = gc();
  x = 0;
  int neg = 0;
  for(;((c<48 || c>57) && c != '-');c = gc());
  if(c=='-') {neg=1;c=gc();}
  for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
  if(neg) x=-x;
}
long long read_long(long long &x)
{
	register int c = gc();
  x = 0;
  int neg = 0;
  for(;((c<48 || c>57) && c != '-');c = gc());
  if(c=='-') {neg=1;c=gc();}
  for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
  if(neg) x=-x;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin>>t;
    read_int(t);
    while(t--)
    {
        iset.clear();
        sum=0;
        flag=true;
        //cin>>n>>k>>m;
        read_int(n);
        read_int(k);
        read_int(m);
        meths methArr[m];
        vector<ll> negs;
        for(int i=0;i<n;i++)
        {
            L[i].clear();
            R[i].clear();
            //cin>>dat[i];
            read_long(dat[i]);
            if(dat[i]<0)
                flag=false,
                negs.push_back(i);
            else
              sum+=dat[i];
            //dat[i]=-1*dat[i];
        }
        for(int i=0;i<m;i++)
        {
            //cin>>methArr[i].l>>methArr[i].r>>methArr[i].c;
            read_int(methArr[i].l);
            read_int(methArr[i].r);
            read_int(methArr[i].c);
        }
        if(flag)
            //cout<<sum<<endl;
            printf("%lld\n", sum);
         else
        {
            for(int i=0;i<m;i++)
            {
                methArr[i].l--;
                methArr[i].r--;
                //cout<<methArr[i].l<<" -> "<<methArr[i].r<<endl;
                L[methArr[i].l].push_back(i);
                R[methArr[i].r].push_back(i);
            }
            for(int i=0;i<n;i++)
            {
                //cout<<L[i].size()<<" : "<<R[i].size()<<endl;
                for(int j=0;j<L[i].size();j++)
                {
                    iset.insert(pii(methArr[L[i][j]].c, L[i][j]));
                }
                if(iset.empty())
                    cost[i]=INF;
                else
                    cost[i]=iset.begin()->first;
                for(int j=0;j<R[i].size();j++)
                {
                    iset.erase(pii(methArr[R[i][j]].c, R[i][j]));
                }
                //cout<<cost[i]<<" ";
                //cout<<dat[i]<<" ";
            }
            //cout<<endl;
            /*for(int i=0; i<=n;i++)
            {
                for(int j=0;j<=k;j++)
                {
                    if(i==0 || j==0)
                        dp[i][j]=0;
                    else if(cost[i-1]<=j)
                        dp[i][j] = max(dat[i-1]+dp[i-1][j-cost[i-1]], dp[i-1][j]);
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }*/

            for(ll i=0;i<n;i++)
            {
                if(dat[i]>=0)
                    sum=sum+dat[i];
                else
                    negs.push_back(i);
            }
            for(ll i=0;i<=negs.size();i++)
            {
                ll x=negs[i-1];
                for(ll w=0;w<=k;w++)
                {
                    if(i==0)
                        dp[i][w]=0;
                    else if(cost[x]<=w)
                        dp[i][w]=max(dat[x]+dp[i-1][w],dp[i-1][w-cost[x]]);
                    else
                        dp[i][w]=dat[x]+dp[i-1][w];
                }
            }
            //cout<<sum<<" : "<<dp[n][k]<<endl;
            //cout<<(sum+dp[n][k])<<endl;
            printf("%lld %lld\n", (sum), (dp[negs.size()][k]));
            printf("%lld\n", (sum+dp[negs.size()][k]));
        }
    }
    return 0;
}
