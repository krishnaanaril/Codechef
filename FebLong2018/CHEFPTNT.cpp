/*
	Swamy Saranam

	Date	: 03/02/2018 09:51:17
	Author	: Krishna Mohan A M
	Problem	: https://www.codechef.com/FEB18/problems/CHEFPTNT
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

ll t, n, m, k, x, ec, oc;
string st;
ll dat[15], cmp;

int main()
{
      FASTIO
      cin>>t;
      while(t--){
            ec = oc = cmp = 0;
            REP(i, 15)
                  dat[i] = 0;
            cin>>n>>m>>x>>k;
            cin>>st;
            assert(st.size()==k);
            REP(i, k){
                  if(st[i]=='E')
                        ec++;
                  else
                        oc++;
            }
            if(x*m <n || k<n){
                  cout<<"no\n";
            }
            else{
                  FOR(i, 1, m+1){
                        if(i&1){
                              dat[i] = min(oc, x);
                              oc = max(oc-dat[i], 0LL);
                        }
                        else{
                              dat[i] = min(ec, x);
                              ec  = max(ec-dat[i], 0LL);
                        }
                        cmp += dat[i];
                        // cout<<dat[i]<<" ";
                  }
                  // cout<<"\n";
                  if(cmp >= n){
                        cout<<"yes\n";
                  }
                  else{
                        cout<<"no\n";
                  }
            }
      }
      return 0;
}
