#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int link=0;
	int pearl=0;
	for (int i=0;i<s.length();i++)
	{
		link+=(s[i]=='-');
		pearl+=(s[i]=='o');
	}
//	cout<<pearl<<"\n";
//	return 0;
	if (link==0 || pearl==0)
	 cout<<"YES\n";
	else
	 if (link%pearl==0)
	  cout<<"YES\n";
	 else
	  cout<<"NO\n";
}
