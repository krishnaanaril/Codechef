#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t, n, sw, flaga, f, cnta, flagb, cntb;
	string dat[2];
	cin>>t;
	while(t--)
	{
		cin>>dat[0]>>dat[1];
		n=dat[0].size();
		cnta=sw=flaga=f=0;
		for(int i=0;i<n;i++)
		{
			if(dat[f][i]=='#')
				f^=1, sw=1;
			if(sw && dat[f][i]!='#')
			{
				sw=0;
				if(i>0)
					cnta++;
			}
			else if(dat[f][i]=='#')
			{
				flaga=1;
				break;
			}
		}
		f=1;
		cntb=sw=flagb=0;
		for(int i=0;i<n;i++)
		{
			if(dat[f][i]=='#')
				f^=1, sw=1;
			if(sw && dat[f][i]!='#')
			{
				sw=0;
				if(i>0)
					cntb++;
			}
			else if(dat[f][i]=='#')
			{
				flagb=1;
				break;
			}
		}
		//  cout<<cnta<<" : "<<cntb<<endl;
		if(flaga && flagb)
			cout<<"No"<<endl;
		else
			cout<<"Yes\n"<<min(cnta, cntb)<<endl;
	}
	return 0;
}
