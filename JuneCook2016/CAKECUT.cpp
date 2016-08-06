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

const int mod = 1000000007;

int n, m;
vector<string> a, b;
string tmp;
int dat[1505][1505], odd[1505][1505], even[1505][1505];

int solve(vector<string> in)
{
    memset(dat, 0, sizeof(dat));
    memset(odd, 0, sizeof(odd));
    memset(even, 0, sizeof(even));
    int res = 0;
    FOR(i, 1, n+1)
    {
        FOR(j, 1, m+1)
        {
            dat[i][j] = dat[i-1][j]+dat[i][j-1]-dat[i-1][j-1]+(in[i-1][j-1]-'0');
        }
    }
    /*REP(i, n+1)
    {
        REP(j, m+1)
            cout<<dat[i][j]<<" ";
        cout<<endl; 
    }
    cout<<endl;*/
    int oddc= 0;
    for(int i=n; i>0; i--)
    {
        for(int j=m; j>0; j--)
        {
            if(dat[i][j]%2 !=0 )
                oddc++;
            odd[i][j] = odd[i+1][j] + odd[i][j+1] - odd[i+1][j+1] + (dat[i][j]%2 !=0 );
        }
    }
    /*REP(i, n+1)
    {
        REP(j, m+1)
            cout<<odd[i][j]<<" ";
        cout<<endl; 
    }
    cout<<endl;*/
    for(int i=n; i>0; i--)
    {
        for(int j=m; j>0; j--)
        {
            even[i][j] = even[i+1][j] + even[i][j+1] - even[i+1][j+1] + (dat[i][j]%2 ==0 );
        }
    }
    /*REP(i, n+1)
    {
        REP(j, m+1)
            cout<<even[i][j]<<" ";
        cout<<endl; 
    }
    cout<<endl;*/
    FOR(i, 1, n+1)
    {
        FOR(j, 1, m+1)
        {
            //cout<<dat[i][j];
            if(dat[i][j]&1)
                res+=odd[i][j];
            else
                res+=even[i][j];
            //cout<<"-"<<res<<" ";
        }
        //cout<<endl;
    }
    /*FOR(i, 1, n+1)
    {
        FOR(j, 1, m+1)
        {
            FOR(k, i, n+1)
            {
                FOR(l, j, m+1)
                {
                    if(i==k && j==l)
                    {
                        if(dat[i][j]%2==0)
                            res++;
                    }
                    else
                    {
                        if((dat[k][l] - dat[i][j])%2==0)
                            res++;
                    }
                }
            }
        }
    }*/
    res-=oddc;
    //cout<<"Res: "<<res<<endl;
    return res;
}
int main()
{
    FASTIO
    cin>>n>>m;
    REP(i, n)
    {
        cin>>tmp;
        a.pb(tmp);
        /*reverse(tmp.begin(), tmp.end());
        b.pb(tmp);*/
    }
    cout<<solve(a)<<endl;
    return 0;
}
