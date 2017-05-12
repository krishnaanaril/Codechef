#include <bits/stdc++.h>

using namespace std;

int n, m, t, r, c ;
string s;

bool search(int a, int b){
    int nxtx =a, nxty =b;
    for(char ch : s){
        if(ch=='L')
            nxty--;
        else if(ch=='R')
            nxty++;
        else if(ch=='U')
            nxtx--;
        else if(ch=='D')
            nxtx++;
        if(nxtx<0 || nxtx >= n || nxty <0 || nxty>=m)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        cin>>s;
        bool isPos = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                if(search(i, j))
                    isPos=true;
        }
        if(isPos)
            cout<<"safe\n";
        else
            cout<<"unsafe\n";
    }
    return 0;
}
