/*
	Swamy Saranam

	Date	: 15/08/2016 10:19:56
	Author	: Krishna Mohan A M
	Problem	:
	Status	:
*/
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
#define sendl           " \n"

const int mod = 1000000007;
ll st[2][200005], en[2][200005], stf[200005], enf[200005];
ll t, n, tmp, s, e;
vi dat;

int main()
{
    FASTIO
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
      cin>>s>>e;
      s--, e--;
      ll ans = ((ll)1)<<60;
      if(s==e)
        ans = 0;
      else
      {
        //cout<<s<<" : "<<e<<endl;
        //To the right
        //cout<<"Right:\n";
        st[0][s] = st[1][s] = 0;
        en[0][e] = en[1][e] = 0;
        for(int i=(s+n+1)%n, k=(e+n+1)%n, j=0; j<n-1; j++, i=(i+n+1)%n, k=(k+n+1)%n)
        {
          //int ci = (i+n)%n;
          //int ck = (k+n)%n;
          //cout<<k<<" "<<dat[(k+n-1)%n]<<" "<<en[0][(k+n-1)%n]<<endl;
          st[0][i] = dat[(i+n-1)%n] + st[0][(i+n-1)%n];
          en[0][k] = dat[(k+n-1)%n] + en[0][(k+n-1)%n];
        }
        //To the left
        //cout<<"Left:\n";
        for(int i=(s+n-1)%n, k=(e+n-1)%n, j=0; j<n-1; j++, i=(i+n-1)%n, k=(k+n-1)%n)
        {
          //int ci = (i+n)%n;
          //int ck = (k+n)%n;
          //cout<<k<<" "<<dat[(k+n-1)%n]<<" "<<en[0][(k+n+1)%n]<<endl;
          st[1][i] = dat[(i+n)%n] + st[1][(i+n+1)%n];
          en[1][k] = dat[(k+n)%n] + en[1][(k+n+1)%n];
        }
        REP(i, n)
        {
          stf[i] = min(st[0][i], st[1][i]);
          enf[i] = min(en[0][i], en[1][i]);
        }
        /*REP(i, n)
          cout<<stf[i]<<sendl[i==n-1];
        REP(i, n)
          cout<<enf[i]<<sendl[i==n-1];*/
        //cout<<ans<<endl;
        REP(k, n)
        {
          ans = min(ans, stf[k]+enf[k]);
        }
      }
      cout<<ans<<endl;
    }
    return 0;
}
