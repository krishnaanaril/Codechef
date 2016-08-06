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

int t;
ll k, res;

int main()
{
    FASTIO  
    cin>>t;
    while(t--)
    {
        res = 0;
        cin>>k;
        k--;
        ll x = 1, div = 5, mul= 10;
        ll p = pow(div, x);
        while(p<=k)
        {
            p = pow(div, ++x);
        }        
        while(k)
        {
            p = pow(div, --x);
            //cout<<p<<" "<<x<<endl;
            res+= ((k/p)*(ll)2*pow(mul, x));
            k%=p;
        }
        cout<<res<<endl;
    }   
    return 0;
}

