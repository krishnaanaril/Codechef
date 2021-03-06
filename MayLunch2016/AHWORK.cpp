#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double, double>	pdd;
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
#define EPS             1e-6

const int mod = 1000000007;
const int INF = 1<<20;

int memo[1005][1005][5][5];
int t, n, ca;
string tmp;
vector<string> dat;

int solve(int i, int j, int cnt1, int cnt2)
{    
    if(i>j)
    {
        if(cnt1 == 0 && cnt2 == 0)
            return 0;
        else
            return n+1;
    }
    if(i==j)
    {
        int idx1 = cnt1, idx2 = dat[i].size()-cnt2-1;
        if(idx1 > idx2)
            return n+1;
        int ans = n+1;
        if(cnt1 ==0 && cnt2 == 0)
            ans = 1;
        while(idx1 < idx2)
        {
            if(dat[i][idx1] != dat[i][idx2])
                return min(ans, n+1);
            ++idx1;
            --idx2;
        }
        return 0;
    }
    if(memo[i][j][cnt1][cnt2] != -1)
        return memo[i][j][cnt1][cnt2];
    int ans = n+1;
    if(cnt1 == 0)
        ans = min(ans, 1+solve(i+1, j, 0, cnt2));
    if(cnt2 == 0)
        ans = min(ans, 1+solve(i, j-1, cnt1, 0));
    int sz1 = dat[i].size();
    int sz2 = dat[j].size();
    if(dat[i][cnt1] == dat[j][sz2-cnt2-1])
    {
        if(cnt1+1<sz1 && cnt2+1<sz2)
            ans = min(ans, solve(i, j, cnt1+1, cnt2+1));
        else if(cnt1+1<sz1)
            ans = min(ans, solve(i, j-1, cnt1+1, 0));
        else if(cnt2+1<sz2)  
            ans = min(ans, solve(i+1, j, 0, cnt2+1));
        else
            ans = min(ans, solve(i+1, j-1, 0, 0));
    }
    memo[i][j][cnt1][cnt2] =  ans;
    return ans;
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        memset(memo, -1, sizeof(memo));
        //cout<<INF<<" "<<memo[3][3][3][3]<<endl;
        dat.clear();
        cin>>n;
        REP(i, n)
        {
            cin>>tmp;
            dat.pb(tmp);
        }
        int ans = solve(0, n-1, 0, 0);
        cout<<ans<<endl;
    }
    return 0;
}
