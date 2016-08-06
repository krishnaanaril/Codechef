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

int t, n, m, tmp;
vi dat;
string s;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        dat.clear();
        dat.resize(m, 0);
        REP(i, n)
        {
            cin>>s;
            REP(j, m)
            {
                //cin>>tmp;
                if(s[j]=='1')
                    dat[j]++;
                /*REP(i, m)
                    cout<<dat[i]<<" ";
                cout<<endl;*/
            }
        }
        
        ll res =0;
        REP(i, m)
        {
            res += (dat[i]*(dat[i]-1))/2;
        }
        cout<<res<<endl;
    }
    return 0;
}
