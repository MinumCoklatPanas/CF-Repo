#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int kali=1;
	for (int i=1;i<=m;i++)
	 kali*=2;
	int ans=((1900*m)+(100*(n-m)))*(kali);
	cout<<ans<<"\n";
}