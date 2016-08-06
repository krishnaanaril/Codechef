#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const ll mod = 100000000000000007;

ll n, w, l, htmp, rtmp, beg, end, mid, dat, total;
vll h, r;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>w>>l;
    REP(i, n)
    {
        cin>>htmp>>rtmp;
        h.push_back(htmp);
        r.push_back(rtmp);
    }
    beg = 0;
    end = mod;
    while(beg<=end)
    {
        mid = (beg+end)>>1;
        dat = total = 0;
        REP(i, n)
        {
            dat = h[i]+r[i]*mid;
            if(dat>=l)
                total+=dat;
        }
        cout<<mid<<" = "<<total<<endl;
        if(total>w)
            end = mid-1;
        else if(total<w)
            beg = mid+1;
        else 
            break;
    }
    if(total == w)
        cout<<mid<<endl;
    else
        cout<<beg<<endl;
    /*cout<<end<<endl;
    cout<<mid<<endl;    */
    return 0;
}
