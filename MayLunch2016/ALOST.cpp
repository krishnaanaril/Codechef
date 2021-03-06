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

ll t, n, e, o;

void printAns(ll evenSum, ll oddSum)
{
    REP(i, evenSum-1)
        cout<<"0 ";
    if(oddSum)
        cout<<"1 ";
    REP(i, oddSum-1)
        cout<<"0 ";
    cout<<endl;
}

ll customSquareRoot(ll num)
{
    ll res = sqrt(num);
    if( (res*res) == num) 
        return res;
    else if( ((res-1) * (res-1)) == num)
        return res-1;
    else if( ((res+1) * (res+1)) == num)
        return res+1;
    else
        return -1;
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>n>>e>>o;
        ll disc = ((n+1)*(n+1)) - (4*o);
        ll evenSum, oddSum, ans1, ans2;
        ll sqDisc = customSquareRoot(disc);
        //cout<<"Disc: "<<disc<<endl;
        if(disc >= 0)
        {
            ans1 = (n+1) + sqrt(disc);
            if(ans1%2 == 0)
            {
                evenSum = ans1/2;
                oddSum = (n+1) - evenSum;
                //cout<<evenSum<<" : "<<oddSum<<endl;
                printAns(evenSum, oddSum);
            }
            else
            {
                ans2 = (n+1) - sqrt(disc);
                if(ans2%2 == 0)
                {
                    evenSum = ans2/2;
                    oddSum = (n+1) - evenSum;
                    //cout<<evenSum<<" : "<<oddSum<<endl;
                    printAns(evenSum, oddSum);
                }
                else
                    cout<<"-1"<<endl;
            }
        }
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
