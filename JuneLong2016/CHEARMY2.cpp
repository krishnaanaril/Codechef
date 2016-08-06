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

int num[20], len, cnt, res;
bitset<20> v;
int sum;

void subset(int i)
{
    int prod =1;
    if(i == len)
    {
        bool flag = false;
        REP(j, len)
            if(v[j])
            {
                flag = true;
                //cout<<num[j];
                prod*=num[j];                
            }
        //cout<<endl;
        if(flag)
            sum+=prod;
        //cout<<"Sum: "<<sum<<endl;
    }
    else
    {
        v[i] = true;
        subset(i+1);
        v[i] = false;
        subset(i+1);
    }
    //return sum;
}

void printNum(int len)
{
    for(int i=len-1; i>=0;i--)
        cout<<num[i];
    cout<<endl;
}

int main()
{
    FASTIO
    REP(i, 1000001)
    {
        v.reset();
        memset(num, 0, sizeof(num));
        len = 0;
        int tmp = i;
        sum = 0;
        if(i>0)
        {
            while(tmp)
            {
                num[len] = tmp%10;
                tmp/=10;
                len++;            
            }
            //printNum(len);
            //cout<<i<<" "<<len<<endl;
            
            subset(0);
        }           
        //cout<<i<<" Res: "<<sum<<endl;
        if(sum%2==0)
        {
            cnt++;
            cout<<cnt<<" - "<<i<<endl;
        }
    }
    return 0;
}
