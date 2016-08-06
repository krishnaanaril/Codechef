#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

typedef unsigned long long ll;

int t, n, h;
ll dat[MAX];
const ll INF = 10e18;

void update(int idx, int val)
{
    while(idx<=n)
    {
        dat[idx]+=val;
        idx+=idx&-idx;
    }
}

void update(int a, int b, int val)
{
    update(a, val);
    update(b+1, -val);
}

ll getSingle(int idx)
{
    ll sum=dat[idx];
    if(idx>0)
    {
        int z = idx-(idx&-idx);
        idx--;
        while(idx!=z)
        {
            sum-=dat[idx];
            idx-=idx&-idx;
        }
    }
    return sum;
}

ll read(int idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=dat[idx];
        idx-=idx&-idx;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>t;
    int x, y;
    ll currVal, minVal;
    while(t--)
    {
        currVal =0;
        memset(dat, 0, sizeof(dat));
        cin>>n>>h;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            update(x+1, 1);
            update(y+2, -1);            
        }
        for(int i=1;i<=h;i++)
        {
            currVal+=(n-read(i));
            //cout<<(n-read(i))<<endl;
        }      
        minVal=currVal;
        for(int i=h+1, j=1;i<=n;i++, j++)
        {
            currVal-=(n-read(j));
            currVal+=(n-read(i));
            if(currVal<minVal)
                minVal = currVal;
        }  
        cout<<minVal<<endl;
    }
    return 0;
}
