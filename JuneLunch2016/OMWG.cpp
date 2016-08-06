#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FASTIO          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back
#define x               first
#define y               second

const int mod = 1000000007;

int dat[1005][1005];
int n, m, a, b, c, d, t;

int check(int i, int j)
{
    if(dat[i][j] != -1)
        return 0;
    int res = 0;
    int x[] = {1, -1, 0, 0};
    int y[] = {0, 0, 1, -1};
    REP(k, 4)
    {
        if(dat[i+x[k]][j+y[k]] != -1)
            res++;
    }
    //cout<<i<<" - "<<j<<" -> "<<res<<endl;    
    dat[i][j] = res;    
    return res;
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        memset(dat, -1, sizeof(dat));
        cin>>n>>m;
        int ans = n*(m-1) + m*(n-1);
        cout<<ans<<endl;
    }
    return 0;
}
