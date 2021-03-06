#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)

int mod, t, n, tmp;
string origin, activity;
ll total;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>origin;
        mod = origin == "INDIAN"? 200 : 400;
        total = 0;
        REP(i, n)
        {
            cin>>activity;
            if(activity == "CONTEST_WON")
            {
                cin>>tmp;
                total += 300 + ((tmp>20)? 0 : (20 - tmp));                     
                //cout<<total<<endl;
            } 
            else if(activity ==  "TOP_CONTRIBUTOR")
            {
                total += 300;     
                //cout<<total<<endl;       
            } 
            else if(activity ==  "BUG_FOUND")
            {
                cin>>tmp;
                total += tmp;
                //cout<<total<<endl;
            }
            else if(activity ==  "CONTEST_HOSTED")
            {
                total += 50;
                //cout<<total<<endl;
            }
        }
        //cout<<total<<endl;
        cout<<(total/mod)<<endl;
    }
    return 0;
}
