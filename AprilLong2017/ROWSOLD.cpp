/*
	Swamy Saranam

	Date	: 11/04/2017 22:14:07
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

#define FASTIO                ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define FOR(i,a,b)            for(int i=(a);i<(b);i++)
#define REP(i,n)		      FOR(i,0,n)
#define SORT(v)               sort((v).begin(),(v).end())
#define UN(v)                 SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)               memset(a,b,sizeof a)
#define pb                    push_back
#define x                     first
#define y                     second
#define endl                  "\n"
#define sendl                 " \n"

const int mod = 1000000007;

int t, n, m;
string st;
vi pos;
ll ans;

int main()
{
      FASTIO
      cin>>t;
      while(t--){
            cin>>st;
            pos.clear();
            n = st.size();
            ans = 0;
            REP(i, n){
                  if(st[i]=='1')
                        pos.pb(n-1-i);
            }
            pos.pb(-1);
            m = pos.size();
            /*REP(i, m)
                  cout<<pos[i]<<" ";
            cout<<"\n";*/
            FOR(i, 1, m){
                  //cout<<i<<" : "<<((pos[i-1] - pos[i] -1) * i + i)<<"\n";
                  ll tmp = 1LL*(pos[i-1] - pos[i] -1) * i;
                  ans += tmp;
                  if(tmp)
                        ans += i;
            }
            cout<<ans<<"\n";
      }
      return 0;
}
