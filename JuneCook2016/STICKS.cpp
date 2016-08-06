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

int t, n, tmp;
map<int, int> mp;
map<int, int>::reverse_iterator it;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>n;
        REP(i, n)
        {
            cin>>tmp;
            mp[tmp]++;
        }
        int res = 1;
        int side = 0;
        for(it=mp.rbegin(); it!= mp.rend(); it++)
        {
            //cout<<it->x<<" "<<it->y<<endl;
            if(it->y >= 4 && side==0)
            {
                res = it->x*it->x;
                break;
            }
            else if(it->y >= 2)
            {
                //cout<<it->y<<endl;
                res*=it->x;                
                side++;
                if(side==2)
                    break;
            }
        }
        if(it==mp.rend())
            cout<<"-1"<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}
