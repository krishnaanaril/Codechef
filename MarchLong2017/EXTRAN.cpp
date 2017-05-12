#include <bits/stdc++.h>

using namespace std;

int t, n, tmp;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        priority_queue<int> pq;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>tmp;
            pq.push(tmp);
        }
        while(!pq.empty()){
            tmp = pq.top();
            pq.pop();
            if(tmp==pq.top() || tmp-pq.top() > 1){
                if(pq.size() > 1)
                    cout<<tmp<<"\n";
                else
                    cout<<pq.top()<<"\n";
                break;
            }
        }
    }
    return 0;
}
