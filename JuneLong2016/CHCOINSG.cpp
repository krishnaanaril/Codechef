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
#define M               100005
#define LIM             1000000005

const int mod = 1000000007;

int t;
ll n;

int main()
{
    FASTIO  
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll res = n%6;
        if(res != 0)
            cout<<"Chef"<<endl;
        else
            cout<<"Misha"<<endl;
    }
    return 0;
}
