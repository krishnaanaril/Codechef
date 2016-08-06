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
#define endl            "\n"

const int mod = 1000000007;
const int m = 1e6+1;

int t, n;
ll tmp;
vector<ll> dat;
bitset<m> isPrime;

void init()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    FOR(i, 2, m)
        if(isPrime[i])
        {
            for(int j=2*i; j<m; j= j+i)
                isPrime[j] = 0;
        }
}

bool isSquare(ll n)
{
    ll rt = sqrt(n);
    if(abs(n-(rt*rt)) < 1e-6)
        return true;
    return false;
}

int main()
{
    FASTIO
    //init();
    cin>>t;
    while(t--)
    {
        dat.clear();
        cin>>n;
        REP(i, n)
        {
            cin>>tmp;
            dat.pb(tmp);
        }
        ll g  = 0;
        bool flg = 0;
        REP(i, n)
        {
            FOR(j, i+1, n)
            {
                g = __gcd(dat[j], dat[i]);
                if(g>1)
                {
                    cout<<g<<endl;
                    flg = 1;
                    break;
                }
            }
            if(flg)
                break;
        }
        if(g<=1)
        {
            bool flg = 0;
            REP(j, n)
            {
                for (long long i = 1; i*i*i <= dat[j]; i++) 
                {
                    if(i>1 && dat[j]%(i*i)==0)
                    {
                        //cout<<dat[j]<<" - "<<i<<endl;
                        cout<<i<<endl;
                        flg = 1;
                        break;
                    }
                    /*if (dat[j] % i == 0) {
                        long long p = dat[j] / i;
                        long long t = (long long)sqrt(p) + 1E-6;
                        if (t > 1 && t*t == p) {
                            cout << t << endl;
                            flg = 1;
                            break;
                        }
                    }*/
                    if(dat[j]%i==0 && isSquare((ll)dat[j]/i) && (ll)sqrt(dat[j]/i)>1)
                    {
                        //cout<<dat[j]<<" - "<<i<<endl;
                        cout<<(ll)sqrt(dat[j]/i)<<endl;
                        flg = 1;    
                        break;
                    }
                }
                if(flg)
                    break;
            }
        }
    }
    return 0;
}
