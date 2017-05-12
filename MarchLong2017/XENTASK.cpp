#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int t, n, tmp;
ll a, b, c, d, ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        a = b = c = d = 0;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>tmp;
            if(i&1)
                b += tmp;
            else
                a += tmp;
        }
        for(int i=0; i<n; i++){
            cin>>tmp;
            if(i&1)
                d += tmp;
            else
                c += tmp;
        }
        ans  = min(a+d, c+b);
        cout<<ans<<"\n";
    }
    return 0;
}
