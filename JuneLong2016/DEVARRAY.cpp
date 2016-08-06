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

ll n, q, maxVal = -1, minVal = -1, tmp;

int main()
{
    FASTIO
    cin>>n>>q;
    REP(i, n)
    {
        cin>>tmp;
        if(i==0)
        {
            maxVal = minVal = tmp;
        }
        maxVal = max(maxVal, tmp);
        minVal = min(minVal, tmp);
    }
    REP(i, q)
    {
        cin>>tmp;
        if(tmp>=minVal && tmp<=maxVal)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    return 0;
}
