/*
	Swamy Saranam

	Date	: 25/03/2017 18:52:04
	Author	: Krishna Mohan A M
	Problem	:
	Status	:
*/
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
#define endl            "\n"
#define sendl           " \n"

const int mod = 1000000007;

int t, n, b, ans;
string s;

int main()
{
    FASTIO
    cin>>t;
    while(t--){
        cin>>n;
        ans = 0;
        bool flag = true;
        REP(i, n){
            cin>>s;
            b = (s=="cookie" ? 1 : 0);
            cout<<s<<" "<<b<<" "<<ans<<"\n";
            if(b && !ans)
                ans = 1;
            else if(ans && b){
                flag = false;
                break;
            }
            else if(ans && !b)
                ans = 0;
        }
        if(ans)
            flag = false;
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
