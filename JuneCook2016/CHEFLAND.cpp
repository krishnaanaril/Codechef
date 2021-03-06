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

map<int, int> mp;
int n, m, a, b, cnt;
map<int, int>::iterator it;

int main()
{
    FASTIO
    cin>>n>>m;
    REP(i, m)
    {
        cin>>a>>b;
        mp[a]++;
        mp[b]++;
    }
    //cout<<mp.size()<<endl;
    for(it = mp.begin(); it!=mp.end(); it++)
    {
        if(it->y < 2)
            cnt++;
    }
    //cout<<"cnt: "<<cnt<<endl;
    if(cnt<=2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
    
}
