#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, dat[10001], cnt, one, mtone, sz;
    string str;
    cin>>t;
    while(t--)
    {
        memset(dat, 0, sizeof(dat));
        cin>>str;
        sz = str.size();
        cnt=0;
        for(int i=0;i<sz;i++)
        {
            if(str[i]=='B')
                dat[cnt]++;
            else if(str[i]=='W' && dat[cnt]!=0)
                cnt++;
        }
        if(dat[cnt]!=0)
            cnt++;
        one = mtone=0;
        
        for(int i=0;i<cnt;i++)  
        {
            //cout<<dat[i]<<" ";
            if(dat[i]==1)
                one++;
            else
                mtone++;
        }
        //cout<<endl;
        //cout<<one<<" : "<<mtone<<endl;
        if(one>0 && mtone>0)
        {
        one%=2;
        mtone%=2;
        if(one^mtone)
            cout<<"Aleksa"<<endl;
        else
            cout<<"Chef"<<endl;
        }
        else if(one>0)
        {
            if(one%2)
            cout<<"Aleksa"<<endl;
        else
            cout<<"Chef"<<endl;
        }
        else if(mtone>0)
        {
            if(mtone%2)
            cout<<"Aleksa"<<endl;
        else
            cout<<"Chef"<<endl;
        }
        else
            cout<<"Chef"<<endl;
    }
    return 0;
}

