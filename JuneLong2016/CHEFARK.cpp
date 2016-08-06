#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double, double>	pdd;
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
#define EPS             1e-6

const int mod = 1000000007;

int t, n, k, zc;
ll fact[100002];

void init()
{
    fact[0] = fact[1] = 1;
    FOR(i, 2, 100002)
        fact[i] = ((ll)i*fact[i-1])%mod;
}

ll modPow(int n, int k)
{
    ll res = 1;
    if(k==1)
        return n;
    if(k&1)
    {
        res = modPow(n, k-1);
        res = (n*res)%mod;
    }
    else
    {
        ll tmp = modPow(n, k/2);
        res = (tmp*tmp)%mod;
    }
    return res;
}

int main()
{
    FASTIO
    init();
    ll res, tp;
    cin>>t;
    while(t--)
    {
        res = 0;
        zc = 0;
        cin>>n>>k;
        REP(i, n)
        {
            cin>>tp;
            if(tp==0)
                zc++;
        }
        n-=zc;
        REP(i, min(k+1, n+1))
        {
            ll tmp=0;
            if(zc || (k-i)%2==0)
            {
                tmp = fact[n];
                tmp = (tmp*modPow(fact[i], mod-2))%mod;
                tmp = (tmp*modPow(fact[n-i], mod-2))%mod;
            }
            res = (res+tmp)%mod;
        }
        cout<<res<<endl;
    }
    return 0;
}
