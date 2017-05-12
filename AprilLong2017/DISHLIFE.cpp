/*
	Swamy Saranam

	Date	: 11/04/2017 21:49:30
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

int n, k, t, m, cnt;
set<int> st;

int main()
{
      FASTIO
      cin>>t;
      while(t--){
            cin>>n>>k;
            st.clear();
            cnt = 0;
            REP(i, n){
                  cin>>m;
                  int pre = st.size();
                  REP(j, m){
                        int tmp;
                        cin>>tmp;
                        st. insert(tmp);
                  }
                  if(st.size() > pre)
                        cnt++;
            }
            //cout<<cnt<<" "<<st.size()<<"\n";
            if(st.size() < k){
                  cout<<"sad\n";
            }
            else if(st.size() == k && cnt < n){
                  cout<<"some\n";
            }
            else if(st.size()==k && cnt==n){
                  cout<<"all\n";
            }
      }
      return 0;
}
