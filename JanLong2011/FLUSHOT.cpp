#include <bits/stdc++.h>

using namespace std;

#define MAX 10001
const double EPS = 1e-8;

double dat[MAX];

bool isSolveable(int n, double t, double d)
{
    double x=max(0.0, dat[0]-d);
    for(int i=1; i<n; i++)
    {
        if(dat[i]+d<x+t)
            return false;
        x = max(dat[i]-d, x+t);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int k, n;
    double lo, hi, mid, t;
    cin>>k;
    while(k--)
    {
        cin>>n>>t;
        for(int i=0;i<n;i++)
            cin>>dat[i];
        //cout<<dat[0]<<endl;
        lo=0, hi=1;
        while(!isSolveable(n, t, hi))
            hi*=2;
        //cout<<hi<<endl;
        while(lo+EPS<hi)
        {
            //cout<<lo<<":"<<hi<<endl;
            mid = (lo+hi)/2;
            if(isSolveable(n, t, mid))
                hi=mid;
            else
                lo=mid;
        }
        cout<<setprecision(4)<<fixed<<lo<<endl;
    }
    return 0;
}
