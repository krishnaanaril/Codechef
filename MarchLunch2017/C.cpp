/*
	Swamy Saranam

	Date	: 25/03/2017 21:12:35
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
const int N = 15e5+5;

int t, n, a, b, diff;
int dp1[N], dp2[N];
int dat[N];

int main()
{
    FASTIO
    cin>>t;
    while(t--){
        priority_queue<pii> pq;
        cin>>n>>a>>b;
        dat[0] = -1;
        REP(i, n){
            cin>>dat[i+1];
        }
        n++;
        int out = n; // haircuts possible outside current segment
        int tmp = 0;
        for(int i=n-1; i>=0; i--){
            while(out >=1 && dat[out-1] - dat[i] >= a+1){
                --out;
                tmp = max(tmp, dp2[out]);
            }
            dp1[i] = tmp+1;
            pq.push(pii(i+dp1[i], dat[i]));
            while(pq.top().y - dat[i] > b-a)
                pq.pop();
            dp2[i] = pq.top().x - i;
        }
        /*cout<<out<<"\n";
        REP(i, n)
            cout<<i<<" "<<dp1[i]<<" "<<dp2[i]<<"\n";*/
        cout<<dp1[0]-1<<"\n";
    }
    return 0;
}
