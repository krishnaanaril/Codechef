#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, x, ans;
    vector<int> dat;
    vector<int>::iterator it;
    cin>>t;
    while(t--)
    {
        dat.clear();
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x==0)
                dat.insert(dat.begin(), i+1);
            else
            {
                it = find(dat.begin(), dat.end(), x);
                ans+= min(it-dat.begin()+1, dat.end()-it-1);
                //cout<<"X:"<<x<<" Pos: "<<(it-dat.begin()+1)<<" : "<<(dat.end()-it-1)<<" int. ans:"<<ans<<endl;
                dat.insert(it+1, i+1);
            }
            /*for(it=dat.begin();it!=dat.end();it++)
                cout<<*it<<" ";
            cout<<endl;*/
        }
        cout<<ans<<endl;
    }    
    return 0;
}
