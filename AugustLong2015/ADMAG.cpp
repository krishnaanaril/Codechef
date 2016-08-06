#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const ll MAX = 10e18;

int main()
{
    ios_base::sync_with_stdio(0);
    ll a=0, b=1, c=0, n;
    int i=1, t, beg, end, mid;
    //cout<<MAX<<endl;
    ll dat[500];
    while(c<=MAX)
    {
        c=a+b;
        //cout<<c<<endl;
        dat[i++]=c;
        a=b;
        b=c;
    }
    //cout<<"i: "<<i<<endl;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int j=1;j<i;j++)
        {
            if(dat[j]>n)
            {
                cout<<(j-1)<<endl;
                break;
            }
        }
    }
    return 0;
}
