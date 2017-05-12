#include <bits/stdc++.h>

using namespace std;

int t, n;
string st;
bool found;

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>t;
      while(t--){
            cin>>st;
            n = st.size();
            found = false;
            for(int i=0; i<n; i++){
                  if(st[i]=='1' && found){
                        found = false;
                        //cout<<"NO\n";
                        break;
                  }
                  if(st[i]=='1' && !found){
                        found = true;
                        while(st[i]=='1')
                              i++;
                        i--;
                  }
            }
            if(found)
                  cout<<"YES\n";
            else
                  cout<<"NO\n";
      }
      return 0;
}
