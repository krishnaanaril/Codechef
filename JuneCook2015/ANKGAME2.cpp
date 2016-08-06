#include <bits/stdc++.h>

using namespace std;

#define MAX 100005
#define MOD 1000000007

typedef long long ll;
typedef map<ll, int> mli;
 
int fact[MAX], ifact[MAX], onec; 
mli mp;
ll t, n, x;
 
ll bigMod(ll n, ll k)
{
    ll ans=1;
    while(k)
    {
        if(k&1)
            ans = (ans*n)%MOD;
        n = (n*n)%MOD;
        k>>=1;
    }
    return ans;
}

void init()
{
    fact[0]=ifact[0]=1;
    for(int i=1;i<MAX;i++)
    {
        fact[i] = (fact[i-1]*i)%MOD;
        ifact[i] = bigMod(fact[i], MOD-2)%MOD;
    }
}

ll C(ll n, ll k)
{
    if(k<n)
        return 0;
    cout<<fact[n]<<" : "<<ifact[k]<<" : "<<ifact[n-k]<<endl;
    return (((1LL*fact[n]*ifact[k])%MOD)*ifact[n-k])%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    init();
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            mp[x]++;
        }
        onec = mp[1];
        cout<<"onec: "<<onec<<endl;
        mp.erase(1);
        if(onec==n)
            cout<<(onec%2)<<endl;
        else
        {
            ll res=0;
            for(int i=0;i<=onec;i+=2)
            {
                cout<<"1->"<<C(n-i-1, onec-i)<<endl;
                res = (res+C(n-i-1, onec-i))%MOD;
            }
            cout<<"2->"<<mp.size()<<endl;
            int left = n-onec;
            for(mli::iterator it=mp.begin();it!=mp.end();it++)
            {
                res = (res*C(left, it->second))%MOD;
                left-=it->second;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
