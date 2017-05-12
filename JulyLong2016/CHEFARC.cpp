/*
	Swamy Saranam

	Date	: 17/08/2016 22:50:45
	Author	: Krishna Mohan A M
	Problem	:
	Status	: Accepted
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
int t, n, m, k1, k2;
int dat[105][105], a[105][105], b[105][105];
queue<pii> q;

void init()
{
  REP(i, n)
    REP(j, m)
      a[i][j] = b[i][j] = 0xffffff;
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
      cin>>n>>m>>k1>>k2;
      REP(i, n)
        REP(j, m)
          cin>>dat[i][j];
      init();
      a[0][0] = 0;
      q.push(pii(0,0));
      while(!q.empty())
      {
        pii curr = q.front();
        q.pop();
        for(int i=-k1; i<=k1; i++)
          for(int j=-k1; j<=k1; j++)
          {
              pii next = pii(curr.x+i, curr.y+j);
              if(abs(next.x - curr.x)+abs(next.y - curr.y) > k1)
                continue;
              if(next.x <0 || next.y < 0 || next.x >=n || next.y>=m)
                continue;
              if(dat[next.x][next.y]==0 && a[next.x][next.y] > a[curr.x][curr.y]+1)
              {
                a[next.x][next.y] = a[curr.x][curr.y]+1;
                q.push(next);
              }
          }
      }
      /*REP(i, n)
        REP(j, m)
          cout<<a[i][j]<<sendl[j==m-1];
      cout<<endl;
      cout<<"Before: "<<endl;
      REP(i, n)
        REP(j, m)
          cout<<b[i][j]<<sendl[j==m-1];*/
      b[0][m-1] = 0;
      q.push(pii(0, m-1));
      while(!q.empty())
      {
        pii curr = q.front();
        q.pop();
        for(int i=curr.x-k2; i<=curr.x+k2; i++)
          for(int j=curr.y-k2; j<=curr.y+k2; j++)
          {
              pii next = pii(i, j);
              /*cout<<"curr: "<<curr.x<<" : "<<curr.y<<endl;
              cout<<"next: "<<next.x<<" : "<<next.y<<endl;*/
              if(abs(next.x - curr.x)+abs(next.y - curr.y) > k2)
                continue;
              //cout<<"c1"<<endl;
              if(next.x <0 || next.y < 0 || next.x >=n || next.y>=m)
                continue;
              //cout<<"c2 "<<b[next.x][next.y]<<" "<<b[curr.x][curr.y]<<endl;
              if(dat[next.x][next.y]==0 && b[next.x][next.y] > b[curr.x][curr.y]+1)
              {
                //cout<<"val: "<<b[curr.x][curr.y]<<endl;
                b[next.x][next.y] = b[curr.x][curr.y]+1;
                q.push(next);
              }
          }
      }
      /*REP(i, n)
        REP(j, m)
          cout<<b[i][j]<<sendl[j==m-1];*/
      int ans = 0xffffff;
      REP(i, n)
        REP(j, m)
        {
          int curr=  max(a[i][j], b[i][j]);
          ans = min(ans, curr);
        }
      if(ans==0xffffff)
        cout<<"-1"<<endl;
      else
        cout<<ans<<endl;
    }
    return 0;
}
