/*
	Swamy Saranam

	Date	: 25/03/2017 20:03:33
	Author	: Krishna Mohan A M
	Problem	: SPECIES
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
const int N = 55;

string dat[N];
int n, t;
bitset<N> visit[N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
ll ans, depth;
set<char> neigh;

void init(){
    REP(i, N)
        visit[i].reset();
    ans = 1;
}

bool isGrizzily(pii pt){
    REP(i, 4){
        if(pt.x+dx[i]<0 || pt.x+dx[i]>=n || pt.y+dy[i]<0 || pt.y+dy[i]>=n)
            continue;
        if(dat[pt.x+dx[i]][pt.y+dy[i]] != '.')
            return false;
    }
    //cout<<pt.x<<" "pt.y<<"\n";
    return true;
}

bool checkGrizzily(){
    REP(i, n){
        REP(j, n){
            if(dat[i][j] == 'G' && !isGrizzily(pii(i, j))){
                //cout<<i<<" "<<j<<"\n";
                return false;
            }
        }
    }
    return true;
}

int dfs(pii pt){
    /*++depth;
    if(depth > 10)
        return 0;*/
    //cout<<"->"<<pt.x<<" "<<pt.y<<"\n";
    int ret = 1;
    visit[pt.x][pt.y] = 1;
    REP(i, 4){
        if(pt.x+dx[i]<0 || pt.x+dx[i]>=n || pt.y+dy[i]<0 || pt.y+dy[i]>=n || visit[pt.x+dx[i]][pt.y+dy[i]])
            continue;
        if(dat[pt.x+dx[i]][pt.y+dy[i]] == '?' || dat[pt.x+dx[i]][pt.y+dy[i]] == 'B' || dat[pt.x+dx[i]][pt.y+dy[i]] == 'P'){
            if(dat[pt.x+dx[i]][pt.y+dy[i]] == 'B' || dat[pt.x+dx[i]][pt.y+dy[i]] == 'P')
                neigh.insert(dat[pt.x+dx[i]][pt.y+dy[i]]);
            ret += dfs(pii(pt.x+dx[i], pt.y+dy[i]));
        }
    }
    return ret;
}

void printVisit(){
    REP(i, n){
        REP(j, n)
            cout<<visit[i][j]<<" ";
        cout<<"\n";
    }
}

int solve(){
    ans = 1;
    REP(i, n){
        REP(j, n){
            if((dat[i][j]=='?' || dat[i][j]=='B' || dat[i][j]=='P') && !visit[i][j]){
                neigh.clear();
                if(dat[i][j]=='B' || dat[i][j]=='P')
                    neigh.insert(dat[i][j]);
                depth = 0;
                int cc = dfs(pii(i, j));
                /*cout<<i<<" "<<j<<" : "<<cc<<" : "<<neigh.size()<<"\n";
                printVisit();*/
                if(neigh.size()>1)
                    return 0;
                if(neigh.size()==0 && cc==1)
                    ans = (ans*3)%mod;
                else if(neigh.size()==0 && cc>1)
                    ans = (ans*2)%mod;
            }
        }
    }
    return ans;
}

int main()
{
    FASTIO
    cin>>t;
    while(t--){
        init();
        cin>>n;
        REP(i, n)
            cin>>dat[i];
        if(!checkGrizzily()){
            cout<<"0\n";
        }
        else{
            ans = solve();
            cout<<ans<<"\n";
        }
    }
    return 0;
}
