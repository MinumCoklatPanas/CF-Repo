#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	string ans;
	ans="";
	cin>>s;
	for (int i=0;i<s.length();i+=2)
	{
		ans+=s[i];
	}
	cout<<ans<<"\n";
}