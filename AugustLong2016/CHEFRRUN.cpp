/*
	Swamy Saranam

	Date	: 06/08/2016 11:46:57
	Author	: Krishna Mohan A M
	Problem	: https://www.codechef.com/AUG16/problems/CHEFRRUN
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
int t, n, tmp, ans, found;
vi dat;
bool flag;
//short visited[100005];
bitset<100005> visited, isCycle, isDud;

bool dfs(int start, int node)
{
    //cout<<start<<" : "<<node<<endl;
    if((visited[node] && start==node))
        return true;
    else if(visited[node])
    {
        found = node;
        if(isCycle[node] || isDud[node])
            flag = 1;
        return false;
    }
    visited[node] = 1;
    if(!dfs(start, (node+dat[node]+1)%n))
    {        
        /*if(flag)
            visited[node] = -1;
        else 
            visited[node] = 2;*/
        if(!flag)
            isCycle[node] = 1;
        else
            isDud[node] = 1;
        if(found==node)
            flag = 1;
        return false;
    }    
    isCycle[node] = 1;
    return true;
}

int main()
{
    //FASTIO
    //cin>>t;
    scanf("%d", &t);
    while(t--)
    {
        //cin>>n;
        scanf("%d", &n);
        dat.clear();
        //memset(visited, 0, sizeof(visited));
        visited.reset();
        isCycle.reset();
        isDud.reset();
        REP(i, n)
        {
            //cin>>tmp;
            scanf("%d", &tmp);
            dat.pb(tmp);
        }
        ans = 0;
        REP(i, n)
        {
            flag = 0;
            if(isCycle[i] || (!visited[i] && dfs(i, i)))
                ans++;
            else
                isDud[i] =1;
            /*
            int j;            
            Got TLE
            visited.reset();
            for(j = i; !visited[j]; visited[j] =1, j= (j+dat[j]+1)%n);*/
            /*cout<<"i: "<<i<<" - "<<endl;            
            REP(k, n)
                cout<<visited[k]<<sendl[k==n-1];
            REP(k, n)
                cout<<isCycle[k]<<sendl[k==n-1];*/
            /*if(j==i)
            {
                ans++;
            }*/
        }        
        //cout<<ans<<endl;
        printf("%d\n", ans);
    }
    return 0;
}
