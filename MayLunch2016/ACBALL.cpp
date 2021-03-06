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

int t, sz;
string a, b;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        sz = a.size();
        string ans(sz, '0');
        REP(i, sz)
        {
            if(a[i]==b[i])
            {
                if(a[i]=='B')
                    ans[i]='W';
                else 
                    ans[i]='B';                
            }
            else
                ans[i]='B';
        }
        cout<<ans<<endl;
    }
    return 0;
}
