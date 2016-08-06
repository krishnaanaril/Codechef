#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define REP(i, n) for(int i=0; i<(n); i++)
#define pb push_back

using namespace std;

typedef long long ll;

int t, n;
ll tmp, init, ans;
vector<ll> tim;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {   
        ans = init = 0;
        tim.clear();
        cin>>n;
        REP(i, n)
        {
            cin>>tmp;
            tim.pb(tmp - init);
            init = tmp;
        }
        REP(i, n)
        {
            cin>>tmp;
            if(tmp <= tim[i])
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
