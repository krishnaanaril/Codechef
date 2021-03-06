#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    vector<ll> dat, val;
    ll temp;
    int n, m, irole, ans;
    vector<ll>::iterator up, low;
    char si, role;
    cin>>n>>m;
    val.push_back(0);
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        dat.push_back(temp);
        val.push_back(((i+1)*(i+2))/2);
    }
    sort(dat.begin(), dat.end());
    /*for(int i=0;i<n;i++)
        cout<<dat[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<val[i]<<" ";
    cout<<endl;*/
    for(int i=0;i<m;i++)
    {
        cin>>si>>temp>>role;
        irole=role=='D'?0:1;
        up = upper_bound(dat.begin(), dat.end(), temp);
        low = lower_bound(dat.begin(), dat.end(), temp);
        if(si=='>')
        {          
            //cout<<"Pos U: "<<(up-dat.begin())<<endl;  
            if(up==dat.end())
                ans=0;
            else
                ans = (val[n] - val[up-dat.begin()]);
        }
        else if(si=='<')
        {            
            //cout<<"Pos L : "<<(low-dat.begin())<<endl;
            if(low==dat.end())
                ans = val[n];
            else if(low-dat.begin()==0)
                ans=0;
            else
                ans = val[low-dat.begin()];
        }
        else
        {
            /*cout<<"Pos1: "<<(low-dat.begin())<<endl;
            cout<<"Pos2: "<<(up-dat.begin())<<endl;*/
            if(low==up)
                ans=0;
            else 
                ans = (val[up-dat.begin()] - val[low-dat.begin()]);
        }
        //cout<<endl<<"Ans: "<<ans<<endl<<"Winner: ";
        if((ans+irole)&1)
            cout<<"D";
        else
            cout<<"C";        
    }
    cout<<endl;
    return 0;
}
