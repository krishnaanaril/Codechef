#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i=1, val;
    for(; i<=5; i++)
    {
        cout<<1<<endl<<0<<endl<<"1 "<<i<<endl;
        cout.flush();
        cin>>val;
        if(val==-2)
            break;
    }
    cout<<2<<endl<<i<<endl;
    return 0;
}
