#include <bits/stdc++.h>

#define REP(i, n) for(int i=0; i<(n); i++)

using namespace std;

typedef long long ll;

int n, tmp;
ll sum;

int main()
{
    cin>>n;
    REP(i, n)
    {
        cin>>tmp;
        sum+=tmp;
    }
    int ans = max( (double)n,  ceil((double)sum/2));
    cout<<ans<<endl;
    return 0;
}
