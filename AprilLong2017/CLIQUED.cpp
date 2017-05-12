/*
	Swamy Saranam

	Date	: 14/04/2017 11:39:47
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
typedef pair<pii, ll> ppi;

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
const int N = 1e5+5;

ll dist[N], minVal = 1e15;;
ll n, k, x, m, s, a, b, c, t;
vector<pl> edges[N];
bitset<N> visit;
set<int> vert;

int main()
{
      FASTIO
      cin>>t;
      while(t--){
            minVal = 1e15;
            visit.reset();
            vert.clear();
            cin>>n>>k>>x>>m>>s;
            FOR(i, 1, n+1)
                  dist[i] = 1e15;
            FOR(i, 1, n+1)
                  edges[i].clear();
            dist[s] = 0;
            priority_queue<pl, vector<pl>, greater<pl>> pq;
            /*FOR(i, 1, k+1)
                  FOR(j, i+1, k+1){
                        edges[i].pb(pl(j, x));
                        edges[j].pb(pl(i, x));
                  }*/
            REP(i, m){
                  cin>>a>>b>>c;
                  if(a <= k)
                        vert.insert(a);
                  if(b <= k)
                        vert.insert(b);
                  edges[a].pb(pl(b, c));
                  edges[b].pb(pl(a, c));
            }
            if(s <=k){
                  /*FOR(i, 1, k+1){
                        if(i != s)
                              dist[i] = min(dist[i], x);
                  }*/
                  for(int it : vert){
                        edges[it].pb(pl(s, x));
                        edges[s].pb(pl(it, x));
                  }
            }
            else{
                  for(auto i = vert.begin(),j = vert.begin(); i != vert.end() &&  j != vert.end(); i++, j++){
                        j++;
                        if(j==vert.end())
                              break;
                        //cout<<*i<<" "<<*j<<"\n";
                        edges[*i].push_back(pl(*j, x));
                        edges[*j].push_back(pl(*i, x));
                  }
            }
            //Dijkstra
            pq.push(pl(dist[s], s));
            while(!pq.empty()){
                  pii cur = pq.top();
                  //cout<<cur.x<<" : "<<cur.y<<"\n";
                  pq.pop();
                  if(visit[cur.y])
                        continue;
                  visit[cur.y] = 1;
                  for(pii it : edges[cur.y]){
                        if(dist[it.x] > dist[cur.y] + it.y){
                              dist[it.x] = dist[cur.y] + it.y;
                              pq.push(pl(dist[it.x], it.x));
                        }
                  }
            }
            FOR(i, 1, k+1)
                  minVal = min(minVal, dist[i]);
            FOR(i, 1, k+1)
                  dist[i] = min(minVal+x, dist[i]);
            FOR(i, 1, n+1)
                  cout<<dist[i]<<" ";
            cout<<"\n";
      }
      return 0;
}
