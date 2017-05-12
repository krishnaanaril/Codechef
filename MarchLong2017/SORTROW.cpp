#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n, tmp;
vi dat;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        dat.clear();
        for(int j=0; j<n; j++){
            cin>>tmp;
            dat.push_back(tmp);
        }
        sort(dat.begin(), dat.end());
        for(int it : dat)
            cout<<it<<" ";
        cout<<"\n";
    }
    return 0;
}
