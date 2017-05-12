#include <bits/stdc++.h>

using namespace std;

int t, cnt;
string tmp;
vector<string> dat;

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>t;
      while(t--){
            cnt = 0;
            dat.clear();
            for(int i=0; i<4; i++){
                  cin>>tmp;
                  dat.push_back(tmp);
            }
            for(int i=0; i<4; i++){
                  cin>>tmp;
                  for(int j=0; j<4; j++)
                        if(dat[j]==tmp){
                              //cout<<tmp<<" "<<dat[j]<<"\n";
                              cnt++;
                              break;
                        }
            }
            if(cnt >=2)
                  cout<<"similar\n";
            else
                  cout<<"dissimilar\n";
      }
      return 0;
}
