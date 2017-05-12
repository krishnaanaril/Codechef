/*
	Swamy Saranam

	Date	: 18/08/2016 12:11:43
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
int t, n, minPos, tmp, s;
ll sum;
vi a, b;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
      a.clear();
      b.clear();
      sum = 0;
      cin>>n;
      b.pb(0);
      REP(i, n)
      {
        cin>>tmp;
        sum += tmp;
        b.pb(tmp);
      }
      b.pb(0);
      a.pb(0);
      REP(j, n)
      {
        cin>>tmp;
        sum += tmp;
        a.pb(tmp);
      }
      a.pb(0);
      s=  sum/n;
      /*REP(i, n+2)
        cout<<a[i]<<sendl[i==n+1];
      cout<<endl;
      REP(i, n+2)
        cout<<b[i]<<sendl[i==n+1];
      cout<<endl;*/
      bool ans=  true;
      FOR(i, 1, n+1)
      {
        if(a[i]==s)
          continue;
        if(s<a[i])
        {
          ans = false;
          break;
        }
        for(int j=i-1; j<=i+1; j++)
          if(s-a[i]==b[j])
          {
            a[i] = s;
            b[j] = 0;
            continue;
          }
        if(s-a[i]==b[i-1]+b[i])
        {
          a[i] = s;
          b[i] = b[i-1] = 0;
          continue;
        }
        if(s-a[i]==b[i+1]+b[i])
        {
          a[i] = s;
          b[i] = b[i+1] = 0;
          continue;
        }
        if(s-a[i]==b[i-1]+b[i+1])
        {
          a[i] = s;
          b[i+1] = b[i-1] = 0;
          continue;
        }
        if(s-a[i]==b[i-1]+b[i]+b[i+1])
        {
          a[i] = s;
          b[i] = b[i-1] = b[i+1] = 0;
          continue;
        }
        ans = false;
        break;
      }
      if(ans)
        cout<<s<<endl;
      else
        cout<<"-1"<<endl;
    }
    return 0;
}
