/*
	Swamy Saranam

	Date	: 25/03/2017 18:44:08
	Author	: Krishna Mohan A M
	Problem	: BRLADDER
	Status	: Accepted
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

int n, a, b;

int main()
{
    FASTIO
    cin>>n;
    REP(i, n){
        cin>>a>>b;
        bool flag = false;
        if(a&1){
            if(b==(a+2) || b==(a-2) || b == (a+1))
                flag = true;
        }
        else{
            if(b==(a+2) || b==(a-2) || b==(a-1))
                flag = true;
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
