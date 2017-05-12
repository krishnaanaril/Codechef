#include <bits/stdc++.h>

using namespace std;

int t, n, k;
string s;

bool check(int val){
    char pre = s[0];
    int cnt = 1, res1 = 0, res2=0;
    for(int i=1; i<n; i++){
        if(s[i]==pre)
            cnt++;
        else {
            cnt = 1;
        }
        if(cnt > val){
            res1++;
            int os = cnt%val;
            if(!os)
                pre = s[i]=='1'? '0' : '1';
            else
                pre = s[i];
            cnt = max(1, os);
        }
        else{
            pre = s[i];
        }
    }
    pre = s[n-1];
    cnt = 1;
    for(int i=n-2; i>=0; i--){
        if(s[i]==pre)
            cnt++;
        else{
            cnt = 1;
        }
        if(cnt > val){
            res2++;
            int os = cnt%val;
            if(!os)
                pre = s[i]=='1'? '0' : '1';
            else
                pre = s[i];
            cnt = max(1, os);
        }
        else{
            pre = s[i];
        }
    }
    //cout<<val<<" "<<res1<<" "<<res2<<"\n";
    if(res1 <=k || res2<=k)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    int l, r;
    while(t--){
        cin>>n>>k;
        cin>>s;
        if(k >= n/2)
            cout<<"1\n";
        else{
            l = 1, r = n;
            while(l<r){
                int mid = (l+r)>>1;
                if(check(mid))
                    r = mid;
                else
                    l = mid+1;
            }
            //cout<<l<<" "<<r<<"\n";
            cout<<l<<"\n";
        }
    }

    return 0;
}
