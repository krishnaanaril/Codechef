#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll t, n, x, y, ans;
    cin>>t;
    while(t--)
    {   
        cin>>n;
        if(n==1)
        {
            cin>>x;
            cout<<x<<endl;
        }
        else
        {
            cin>>x>>y;
            ans=gcd(x, y);
            ll i=2;
            while(i<n)
            {
                cin>>x;
                ans=gcd(ans, x);
                i++;
            }
            cout<<(ans*n)<<endl;
        }
    }
    return 0;
}
