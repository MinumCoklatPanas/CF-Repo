#include <bits/stdc++.h>
using namespace std;

int bit(int x)
{
	int ans=0;
	while (x>0)
	{
		++ans;
		x/=2;
	}
	return ans;
}

int main()
{
	int n,m;
	cin>>n>>m;
//	cout<<bit(m)<<"\n";
	while (bit(m)>n)
	{
		int bitt=bit(m);
//		cout<<bitt<<"\n";
		m-=1<<(bitt-1);
//		cout<<m<<" m\n";
	}
	cout<<m<<"\n";
}
