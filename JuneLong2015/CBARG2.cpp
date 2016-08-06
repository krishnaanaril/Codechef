#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

int main()
{
    int t, n, dat[MAX], diff[MAX];
    long long ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        dat[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>dat[i];
            diff[i]=dat[i]-dat[i-1];
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<diff[i]<<" ";
            if(diff[i]>0)
                ans+=diff[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

