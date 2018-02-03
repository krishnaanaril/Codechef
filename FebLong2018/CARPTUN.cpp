/*
	Swamy Saranam

	Date	: 03/02/2018 10:30:12
	Author	: Krishna Mohan A M
	Problem	: https://www.codechef.com/FEB18/problems/CARPTUN
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
double c, d, delay[N];
ll t, n;

int main()
{
      FASTIO
      cin>>t;
      while(t--){
            cin>>n;
            REP(i, n){
                  cin>>delay[i];
            }
            cin>>c>>d>>s;
            tt = d/s;
            REP(i, n){
                  if(i==0){
                        carA[i][0] = 0;
                        carA[i][1] = delay[i];
                  }
                  else{
                        carA[i][0] = carA[i-1][1]+tt;
                        carA[i][1] = carA[i][0]+delay[i];
                  }
                  cout<<carA[i][0]<<" : "<<carA[i][1]<<"\n";
            }
            cout<<"\n";
            REP(i, n){
                  if(i==0){
                        carB[i][0] = 0;
                        carB[i][1] = c*delay[i];
                  }
                  else{
                        carB[i][0] = carB[i-1][1]+tt;
                        carB[i][1] = max(carB[i][0], carA[i][0]+((c-1)*delay[i]))+delay[i];
                  }
                  cout<<carB[i][0]<<" : "<<carB[i][1]<<"\n";
            }
            cout<<"\n";
            assert(carB[n-1][1]>carA[n-1][1]);
            ans = carB[n-1][1] - carA[n-1][1];
            cout<<fixed<<setprecision(10)<<ans<<"\n";
      }
      return 0;
}
