#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5+5;

int fen[N], t, n, m, a, b, type, npos, arr[N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string s;
vector<string> dat;
bitset<N> visit[6];

void add(int pos, int val){
    for(int i=pos; i<=N; i+=i&-i)
        fen[i] ^= val;
}

int query(int pos){
    int res = 0;
    for(int i=pos; i; i-=i&-i)
        res ^= fen[i];
    return res;
}

void init(){
    dat.clear();
    for(int i=0; i<6; i++)
        visit[i].reset();
}

int bfs(pii start){
    int res = 0;
    queue<pii> q;
    q.push(start);
    visit[start.first][start.second] = 1;
    while(!q.empty()){
        pii curr = q.front();
        q.pop();
        res++;
        pii nxt;
        for(int i=0; i<4; i++){
            nxt.first = curr.first+dx[i];
            nxt.second = curr.second+dy[i];
            if(nxt.first >=4 || nxt.second >=4 || nxt.second<0 || nxt.first<0)
                continue;
            if(dat[nxt.first][nxt.second]=='1' && !visit[nxt.first][nxt.second]){
                visit[nxt.first][nxt.second] = 1;
                q.push(nxt);
            }
        }
    }
    //cout<<"Res: "<<res<<"\n";
    return res;
}

int getXOR(){
    int res = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(dat[i][j]=='1' && !visit[i][j]){
                //cout<<i<<" - "<<j<<"\n";
                res ^= bfs(pii(i, j));
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            init();
            for(int j=0; j<4; j++){
                cin>>s;
                dat.push_back(s);
            }
            /*for(string it : dat)
                cout<<it<<"\n";*/
            arr[i] = getXOR();
            //cout<<i<<" : "<<xorVal<<"\n";
            add(i, arr[i]);
        }
        for(int i=0; i<m; i++){
            cin>>type;
            if(type==1){
                cin>>a>>b;
                //cout<<a<<" : "<<b<<" ";
                int res = query(b)^query(a-1);
                if(res !=0)
                    cout<<"Pishty\n";
                else
                    cout<<"Lotsy\n";
            }
            else{
                cin>>npos;
                init();
                for(int j=0; j<4; j++){
                    cin>>s;
                    dat.push_back(s);
                }
                int tmp = arr[npos];
                arr[npos] = getXOR();
                add(npos, tmp^arr[npos]);
            }
        }
    }
    return 0;
}
