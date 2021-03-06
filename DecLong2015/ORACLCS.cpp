#include <bits/stdc++.h>

#define MAX 101

using namespace std;

int t, n, ans, i, j, k;
string qns[MAX], piv;

inline string lcs(string a, string b, int m, int p)
{
    int dp[MAX][MAX];
    cout<<a<<" "<<b<<" "<<n<<endl;
    for(j=0;j<=m;j++)
        for(k=0;k<=p;k++)
        {
            if(j==0 || k==0)
                dp[j][k]=0;
            else if(a[j-1]==b[k-1])
                dp[j][k]=dp[j-1][k-1]+1;
            else
                dp[j][k]=max(dp[j][k-1], dp[j-1][k]);
        }
    /*for(j=0;j<=n;j++)
    {
        for(k=0;k<=n;k++)
        {
            cout<<dp[j][k]<<" ";
        }
        cout<<endl;
    }   */ 
    int ind = dp[m][p];
    cout<<"Ind:"<<ind<<" "<<n<<endl;
    string res(ind, '0');
    if(ind==0)
        return res;
    j=m, k=p;
    while(j>0 && k>0)
    {
        if(a[j-1]==b[k-1])
        {
            res[ind-1]=a[j-1];
            ind--, k--, j--;
        }
        if(dp[j-1][k] > dp[j][k-1])
            j--;
        else
            k--;
    }
    //cout<<"Res:"<<res<<endl;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);    
    cin>>t;
    while(t--)
    {
        cin>>n;
        //cout<<"N: "<<n<<endl;
        for(i=0;i<n;i++)
            cin>>qns[i];
        if(n==1)
            ans = qns[0].size();
        else
        {
            piv=qns[0];
            for(i=1;i<n;i++)
            {
                piv = lcs(piv, qns[i], piv.size(), qns[i].size());
                if(piv.size()==0)
                {
                    break;
                }
            }
            ans=piv.size();
        }
        cout<<ans<<endl;
    }
    return 0;
}
