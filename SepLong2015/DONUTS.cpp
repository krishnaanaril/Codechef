#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t, n, m, ans, i, j, x, onec;
	vector<int> dat;
	cin>>t;
	while(t--)
	{
		dat.clear();
		ans=onec=0;
		cin>>n>>m;
		for(i=0; i<m; i++)
		{
			cin>>x;
			if(x==1)
			    onec++;
			dat.push_back(x);
		}
		ans = m-1;
		if(m>2)
		    ans = ans - min(n/2, onec);
		cout<<ans<<endl;
	}
	return 0;
}
