/*
	Swamy Saranam

	Date	: 03/02/2018 09:17:42
	Author	: Krishna Mohan A M
	Problem	: https://www.codechef.com/FEB18/problems/CHEFCHR
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

int t, sz, cnt;
string st, pat = "cefh", tmp;

int main()
{
      FASTIO
      cin>>t;
      while(t--){
            cin>>st;
            bool isLovely = false;
            cnt = 0;
            sz = st.size();
            REP(i, sz-3){
                  tmp = st.substr(i, 4);
                  SORT(tmp);
                  if(tmp==pat){
                        isLovely = true;
                        cnt++;
                  }
            }
            if(isLovely){
                  cout<<"lovely "<<cnt<<"\n";
            }
            else{
                  cout<<"normal\n";
            }
      }
      return 0;
}
