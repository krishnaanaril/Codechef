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

const int mod = 1000000007;

int dat[11][1005][11][1005];
int arr[1005][1005], sum[1005][1005];
int n, m, a, b, tmp, q, res, curr;

void init()
{
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            sum[i][j] = arr[i][j];
            if(j>0)
                sum[i][j] += arr[i][j-1];
            if(i>0)
                sum[i][j] += arr[i-1][j];
            if(i>0 && j>0)
                sum[i][j] -= arr[i-1][j-1];
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    memset(dat, 0, sizeof(dat));
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            dat[0][i][0][j] = arr[i][j];
        }
        FOR(k, 1, log2(m)+1)
            REP(j, m)
            {
                dat[0][i][k][j] = max(dat[0][i][k-1][j], dat[0][i][k][j+(int)pow(2, k-1)]);
            }
    }
    FOR(l, 1, log2(n)+1)
        FOR(i, 1, n)
            FOR(k, 1, log2(m)+1)
                FOR(j, 1, m)
                {
                    dat[l][i][k][j] = max(dat[l-1][i][k][j], dat[l-1][i+(int)pow(2, l-1)][k][j]);
                }
}

int getMax(int x1, int y1, int x2, int y2)
{
    int lenx = x2-x1+1;
    int kx = log2(lenx);
    int leny = y2-y1+1;
    int ky = log2(leny);
    int max1 = max(dat[kx][x1][ky][y1], dat[kx][x1][ky][y2+1-(int)pow(2, ky)]);
    int max2 = max(dat[kx][x2+1-(int)pow(2, kx)][ky][y1], dat[kx][x2+1-(int)pow(2, kx)][ky][y2+1-(int)pow(2, ky)]);
    return max(max1, max2);
}

int main()
{
    FASTIO
    cin>>n>>m;
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            cin>>arr[i][j];    
        }
    }
    init();
    res = mod;
    cin>>q;
    REP(k, q)
    {
        cin>>a>>b;
        a--;
        b--;
        FOR(i, a, n)
           FOR(j, b, m)
           {
                curr = getMax(i-a, j-b, i, j)*(a+1)*(b+1);
                cout<<getMax(i-a, j-b, i, j)<<" "<<(sum[i][j] - sum[i][j-b] - sum[i-a][j] + sum[i-a][j-b])<<endl;
                curr -= sum[i][j] - sum[i][j-b] - sum[i-a][j] + sum[i-a][j-b];
                res = min(res, curr);
           }            
       cout<<res<<endl;
    }
    return 0;
}
