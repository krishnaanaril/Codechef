#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define REP(i, n) for(int i=0; i<(n); i++)
#define REP2(i, a, n) for(int i=(a); i<(n); i++)
#define pb push_back

using namespace std;

typedef long long ll;

int t, n;
ll tmp, maxVal, minVal, currNum, currMax, ncnt, pcnt;
vector<ll> dat;
const int INF = 1e9+7;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        dat.clear();
        ncnt = pcnt = 0;
        cin>>n;
        REP(i, n)
        {
            cin>>tmp;
            if(i==0)
            {
                maxVal = tmp;
                minVal = tmp;
            }
            else
            {
                maxVal = max(maxVal, tmp);
                minVal = min(minVal, tmp);
            }
            if(tmp<0)
                ncnt++;
            else if(tmp>0)
                pcnt++;
            dat.pb(tmp);
        }
        if(ncnt==n || pcnt==1)            
            cout<<maxVal<<endl;
        else
        {
            ll ans = -1*INF;
            REP(i, n)
            {
                if(dat[i]<0)
                {
                    tmp = dat[i];
                    dat[i] = 0;
                    maxVal = currMax = dat[0];
                    REP2(j, 1, n)
                    {
                        currMax = max(dat[i], currMax+dat[j]);
                        maxVal = max(maxVal, currMax);
                    }
                    //cout<<tmp<<" "<<ans<<" "<<maxVal<<endl;
                    ans = max(ans, maxVal);
                    /*if(ans==9)
                    {
                        REP(k, n)
                            cout<<dat[k]<<" ";
                        cout<<endl;
                    }*/
                    dat[i] = tmp;   
                    
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
