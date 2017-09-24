#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,n;
	string s;
	map<string,int> mp;
	cin>>n;
	mp.clear();
	for (i=1;i<=n;i++)
	{
		cin>>s;
		if (mp[s])
		 cout<<"YES\n";
		else
		 cout<<"NO\n";
		mp[s]++;
	}
}
