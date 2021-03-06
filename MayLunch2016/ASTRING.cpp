#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double, double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;
typedef pair<char, int> pci;

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

int t, k, sz;
string s;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>s>>k;
        sz = s.size();
        if(sz == k)
            cout<<s<<endl;
        else
        {
            set<pci> dat;
            string ans = "";
            REP(i, sz-k+1)
                dat.insert(pci(s[i], i));
            int a = 0, b = (*dat.begin()).y;
            ans += (*dat.begin()).x;
            FOR(i, sz-k+1, sz)
            {
                while(a <= b) dat.erase(pci(s[a], a)), a++;
                dat.insert(pci(s[i], i));
                b = (*dat.begin()).y;
                ans += (*dat.begin()).x;
            }           
            cout<<ans<<endl;
        }
    }
    return 0;
}
