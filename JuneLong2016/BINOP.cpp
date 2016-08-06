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

int t, sz, so, tz, to, n, andC, orC, diff, res, xorC;
string a, b;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        sz = so = tz = to = andC = orC = diff = res = xorC = 0;
        n = a.size();
        REP(i, n)
        {
            if(a[i] == '0')
                sz++;
            else
                so++;
            if(b[i] == '0')
                tz++;
            else
                to++;
            if(a[i] != b[i])
                diff++;
        }
        /*cout<<"n: "<<n<<endl;
        cout<<"sz: "<<sz<<endl;
        cout<<"so: "<<so<<endl;
        cout<<"tz: "<<tz<<endl;
        cout<<"to: "<<to<<endl;*/
        if((sz == 0 && sz != tz) ||
            (so == 0 && so != to))
            cout<<"Unlucky Chef"<<endl;
        else
        {
            if(sz > tz)
            {
                orC = sz - tz;
                //sz--;
                //so++;
            }
            if(so > to)
            {
                andC = so - to;
                //so--;
                //sz++;
            }
            xorC = diff - (orC+andC);
            if(xorC%2 != 0)
                cout<<"Unlucky Chef"<<endl;
            else
            {                
                res = (orC+andC)+(xorC/2);
                cout<<"Lucky Chef"<<endl<<res<<endl;
            }
        }
    }
    return 0;
}
