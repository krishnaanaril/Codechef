#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, t, nxt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        nxt = n+1;
        if(n==1)
            cout<<"2"<<endl;
        else if(n>2 && __builtin_popcountll(nxt)==1)
        {
            cout<<((nxt>>1)-1)<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
