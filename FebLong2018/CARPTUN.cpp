/*
	Swamy Saranam

	Date	: 03/02/2018 11:27:44
	Author	: Krishna Mohan A M
	Problem	:
	Status	:
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pll;

#define FASTIO                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b)            for(int i=(a);i<(b);i++)
#define REP(i,n)              FOR(i,0,n)
#define SORT(v)               sort((v).begin(),(v).end())
#define UN(v)                 SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)               memset(a,b,sizeof a)
#define PB                    push_back
#define F                     first
#define S                     second

const int MOD = 1000000007;
const int N = 1e5+5;

double carA[N][2], carB[N][2], s, tt, ans;
ll t, c, d, delay[N], n;

int main()
{
      FASTIO
      cin>>t;
      while(t--){
            cin>>n;
            ans = 0;
            REP(i, n){
                  cin>>delay[i];
            }
            cin>>c>>d>>s;
            REP(i, n){
                  ans = max(ans, (double)(c-1)*delay[i]);
            }            
            cout<<fixed<<setprecision(10)<<ans<<"\n";
      }
      return 0;
}
