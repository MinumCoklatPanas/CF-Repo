#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	int i=0;
	while (i<s.length())
	{
		while (s[i]!='x')
		 ++i;
		int cnt=0;
		while (s[i]=='x')
		 {
		 	++i;
		 	++cnt;
		 }
		++i;
		ans+=(cnt-2)*(cnt>2);
	}
	cout<<ans<<"\n";
}
