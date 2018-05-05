#include <bits/stdc++.h>
using namespace std;

int cei(int x,int y)
{
	return (x/y)+(x%y!=0);
}

int main()
{
	int k,n,s,p;
	cin>>k>>n>>s>>p;
	int ans=cei(k*cei(n,s),p);
	cout<<ans<<"\n";
}
