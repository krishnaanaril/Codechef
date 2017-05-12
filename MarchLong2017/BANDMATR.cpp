#include <bits/stdc++.h>

using namespace std;

int t, n, zc, ans, l, r, mid, tmp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        zc = 0;
        cin>>n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                cin>>tmp;
                if(!tmp)
                    zc++;
            }
        ans = n-1;
        while(ans*(ans+1) > zc)
            ans--;
        //cout<<zc<<" "<<ans<<": \n";
        ans = n-1-ans;
        cout<<ans<<"\n";
    }
    return 0;
}
