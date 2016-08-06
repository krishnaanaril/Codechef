#include <bits/stdc++.h>

using namespace std;

#define MAX 2001

typedef pair<int, int> pii;
typedef pair<int, pii> ppii;

int main()
{
	ios_base::sync_with_stdio(0);
	int t, n, k, x, y, f;
	char ans[MAX];
	vector<ppii> dat;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		dat.clear();
		memset(ans, -1, sizeof(ans));
		for(int i=0; i<k; i++)
		{
			cin>>x>>y;
			dat.push_back(ppii(y-x+1, pii(x, y)));
			//cout<<dat[i].first<<endl;
		}
		sort(dat.begin(), dat.end());
		
		for(int i=0; i<k; i++)
		{
			f=0;
			for(int j=dat[i].second.first; j<=dat[i].second.second; j++)
			{
				if(ans[j]=='(' || ans[j]==')')
					continue;
				//cout<<"f: "<<f<<endl;
				if(f)
				{
					ans[j]=')';
				}
				else
				{
					ans[j]='(';
				}
				f^=1;
			}
		}
		f=0;
		for(int j=0;j<n;j++)
		{
			if(ans[j]=='(' || ans[j]==')')
				continue;
			//cout<<"f: "<<f<<endl;
			if(f)
			{
				ans[j]=')';
			}
			else
			{
				ans[j]='(';
			}
			f^=1;
		}
		for(int i=0;i<n;i++)
			cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
