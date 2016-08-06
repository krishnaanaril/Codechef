/**/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string a, b;
    int t, sa, sb, f;
    cin>>t;
    while(t--)
    { 
        cin>>a>>b;
        sa = a.size();
        sb = b.size();
        f=0;
        if(sa !=sb)
            cout<<"No"<<endl;
        else
        {
            for(int i=0;i<sa;i++)
            {
                if(a[i]!=b[i] && a[i]!='?' && b[i]!='?')
                {
                    f=1;
                    break;                   
                }   
            }
            //cout<<"f:"<<f<<endl;
            if(!f)
            {
                cout<<"Yes"<<endl;
            }
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
