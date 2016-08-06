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

int t;
double H, S, a, b, c, bac, h;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>H>>S;
        bac = (H*H) - (4*S);
        if(bac<0)
            cout<<"-1"<<endl;
        else
        {
            b = sqrt((H*H)+(4*S));
            h = (b+sqrt((H*H)-(4*S)))/2.0;
            c = (2*S)/h;
            if(h<c)
                swap(c, h);
            cout<<fixed<<setprecision(6)<<c<<" "<<h<<" "<<H<<endl;
        }
    }
    return 0;
}
