#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, maxVal, cnt;
    int w[MAX];
    string a, b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a>>b;
        for(int i=0; i<=n; i++)
            cin>>w[i];
        //a+=a;
        //b+=b;
        //cout<<a<<endl<<b<<endl;
        cnt=0;
        maxVal=w[0];
        for(int i=0; i<n; i++)
        {
            if(a[i]==b[i])
                cnt++;
        }
        //cout<<cnt<<endl;
        if(cnt==n)
            maxVal = max(maxVal, w[cnt]);
        else
            maxVal = max(maxVal, *max_element(w+1, w+cnt+1));
        cout<<maxVal<<endl;
    }
    return 0;
}
