#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

typedef pair<char, int> pci;
//function to check if the given string is regular
inline bool isRegular(string str)
{
    stack<char> stk;
    int sz=str.size();
    for(int i=0;i<sz;i++)
    {
        if(str[i]=='(')
            stk.push(str[i]);
        else if(str[i]==')')
        {
            if(stk.empty())
                return false;
            stk.pop();
        }
    }
    if(stk.empty())
        return true;
    return false;
}

vector<pci> dat;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, k, sz;
    string str;
    cin>>t;
    while(t--)
    {
        dat.clear();
        cin>>str>>k;
        if(!isRegular(str))
        {
            if(k==1)
                cout<<str<<endl;
            else
                cout<<"-1"<<endl;
        }
        else
        {
            sz=str.size();
            dat.push_back(pci(str[0], 1));
            int j=0;
            for(int i=1;i<sz;i++)
            {
                if(str[i]!=str[i-1])
                {
                    j++;
                    dat.push_back(pci(str[i], 0));
                }
                dat[j].second++;
            }
            j++;
            /*for(int i=0;i<j;i++)
                cout<<dat[i].second<<" ";
            cout<<endl;*/
            if(k>j)
                cout<<"-1"<<endl;
            else
            {
                if(k>j/2)
                {
                    k-=j/2;
                    dat[j-(2*k)].second--;
                }
                else
                {
                    dat[2*k-1].second--;
                }
                /*for(int i=0;i<j;i++)
                    cout<<dat[i].second<<" ";
                cout<<endl;*/
                for(int i=0;i<j;i++)
                {
                    for(int k=0;k<dat[i].second;k++)
                        cout<<dat[i].first;
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
