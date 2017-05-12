/*
	Swamy Saranam

	Date	: 08/10/2016 14:08:23
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
int t, n, m, c, rt, ans;

int main()
{
    FASTIO
    cin>>t;
    while(t--){
      cin>>n>>m>>c;
      ans = 0;
      rt = sqrt(c);
      FOR(i, 1, rt+1){
        int div = c/i;
        if(c%i==0){
          if(i<=n && div<=m)
            ans++;
          if(i!=div && div<=n && i<=m)
            ans++;
        }
      }
      cout<<ans<<endl;
    }
    return 0;
}
