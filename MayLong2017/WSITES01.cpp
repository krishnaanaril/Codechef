#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

struct node{
      int pos;
      node *nxt[30];
      node(){
            pos = 0;
      }
};

int t, covered, blocked, bc[N], nbc[N], len, lensum;
string type;
string st;
vector<string> res;

void add(node *head, string s, bool flag){
      if(head==NULL)
            return;
      int sz = st.size();
      for(int i=0; i<sz; i++){
            int nchar = s[i]-'a';
            assert(nchar >=0 && nchar <=26);
            //cout<<s[i]<<" "<<nchar<<"\n";
            if(head->nxt[nchar]==NULL){
                  head->nxt[nchar] = new node();
                  head->nxt[nchar]->pos = ++len;
            }
            if(flag)
                  bc[head->nxt[nchar]->pos]++;
            else
                  nbc[head->nxt[nchar]->pos]++;
            head = head->nxt[nchar];
      }
}

void prints(node *head, string &ans){
      if(head == NULL)
            return;
      if(bc[head->pos]==0)
            return;
      if(nbc[head->pos]==0){
            res.push_back(ans);
            covered += bc[head->pos];
            return;
      }
      for(int i=0; i<30; i++){
            //cout<<"Pushed: "<<(char)('a'+i)<<" : "<<i<<"\n";
            if(head->nxt[i]!=NULL){
                  ans.push_back((char)('a'+i));
                  prints(head->nxt[i], ans);
                  ans.pop_back();
            }
      }
}

void printWrapper(node *head){
      string ans = "";
      for(int i=0; i<30; i++){
            if(head->nxt[i]!=NULL){
                  char ch = (char)('a'+i);
                  assert(ch >='a' && ch<='z');
                  ans.push_back(ch);
                  prints(head->nxt[i], ans);
                  ans.pop_back();
            }
      }
      //cout<<ans<<"\n";
}

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      node *root = new node();
      cin>>t;
      for(int i=0; i<t; i++){
            cin>>type>>st;
            lensum += st.size();
            if(type=="-")
                  blocked++;
            add(root, st, type=="+"?false:true);
      }
      assert(len <= N);
      assert(len <= N);
      printWrapper(root);
      if(blocked != covered){
            cout<<"-1\n";
            return 0;
      }
      cout<<res.size()<<"\n";
      for(string it : res)
            cout<<it<<"\n";
      return 0;
}
