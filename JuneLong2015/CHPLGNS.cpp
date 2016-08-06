#include <bits/stdc++.h>

#define MAX 100005
using namespace std;

typedef pair<int, int> pii;

vector<pii> dat;
int ans[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	int t, n, m, maxx, x, y;
	cin>>t;
	while(t--)
	{
		dat.clear();
		cin>>n;
		for(int i=0; i<n; i++)
		{
			maxx=INT_MIN;
			cin>>m;
			for(int j=0; j<m; j++)
			{
				cin>>x>>y;
				maxx = max(maxx, x);
			}
			dat.push_back(pii(maxx, i));
		}
		sort(dat.begin(), dat.end(), greater<pii>());
		for(int i=0; i<n;i++)
		{
			ans[dat[i].second] = n-1-i;
		}
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
	}
