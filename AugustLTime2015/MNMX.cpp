#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k, minVal;
    cin>>t;
    while(t--)
    {
        minVal=INF;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>k;
            minVal = k<minVal?k:minVal;
        }
        cout<<(1LL*minVal*(n-1))<<endl;
    }
    return 0;
}
