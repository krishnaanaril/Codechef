#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define REP(i, n) for(int i=0; i<(n); i++)
#define REP2(i, a, n) for(int i=(a); i<(n); i++)
#define pb push_back

using namespace std;

typedef long long ll;

int t, k, sz, ans;
string s;
int cnt[30];
vector<int> dat;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {   
        memset(cnt, 0, sizeof(cnt));
        cin>>s>>k;
        sz = s.size();
        dat.clear();
        ans=0;
        REP(i, sz)
        {
            cnt[s[i]-'a']++;
        }
        REP(i, 30)
        {
            if(cnt[i] > 0)
                dat.pb(cnt[i]);
        }
        sort(dat.begin(), dat.end());
        sz = dat.size();
        for(int i=sz-1; i>0; i--)
        {
            if(dat[i]-dat[0]-k > 0)
                ans += dat[i]-dat[0]-k;
        }
        cout<<ans<<endl;
    }
    return 0;
}
