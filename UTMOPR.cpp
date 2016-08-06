#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;

ll bigMod(int a, int b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b>>=1;
    }
    return ans;
}

int main()
{
    int t, n, k, tmp;
    ll last, sum;
    cin>>t;
    while(t--)
    {
        sum=last=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            sum+=tmp;
        }
        //cout<<sum<<endl;
        for(int i=0;i<k;i++)
        {
            last=sum+1;
            sum=((2*sum)%MOD)+1;
            /*cout<<last<<endl;
            cout<<sum<<endl;*/
        }   
        /*if(k>0)    
            last = (bigMod(2, k-1)*sum)%MOD;
        //cout<<last<<endl;
        //cout<<bigMod(2, 1)<<endl;        
        if(k>1)
            last = (last + bigMod(2, k-2))%MOD;
        //cout<<last<<endl;
        if(k>2)
            last = (last + bigMod(2, k-3))%MOD;
        last++;*/
        //cout<<last<<endl;
        if(last&1)
            cout<<"odd"<<endl;
        else
            cout<<"even"<<endl;
    }
    return 0;
}
