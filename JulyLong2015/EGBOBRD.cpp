#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll curr, k, pack, ans, t, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        ans=pack=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>curr;
            ans+=curr;
            if((ans%k)!=0)
                ans++;
            //cout<<"In Ans:"<<ans<<endl;
        }
        //cout<<ceil(5/3)<<":"<<ceil((1.0*5)/3)<<endl;;
        ans=ceil((1.0*ans)/k);
        cout<<ans<<endl;
    }
    return 0;
}
