/*
    Challenge Problem
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int k, n, x, t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> dat(500, 0), cut;
        k=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if((dat[x]&1)!=(k&1))
            {
                cut.push_back(i);
                ++k;
            }
            ++dat[x];
            //cout<<"J"<<endl;
        }
        int sz=cut.size();
        cout<<sz<<endl;
        for(int i=0; i<sz; i++)
            cout<<cut[i]<<" ";
        cout<<endl;;
    }
    return 0;
}
