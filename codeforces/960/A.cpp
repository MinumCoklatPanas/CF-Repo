#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int a=0,b=0,c=0;
	for (int i=0;i<s.length();i++)
	{
		a+=(s[i]=='a');
		b+=(s[i]=='b');
		c+=(s[i]=='c');
	}
	char now=a;
	bool bisa=true;
	int i=0;
	while (s[i]=='a')
	 ++i;
	while (s[i]=='b')
	 ++i;
	if (s[i]=='a')
	{
		cout<<"NO\n";
		return 0;
	}
	while (s[i]=='c')
	 ++i;

	if (i!=s.length())
	 {
	 	cout<<"NO\n";
	 	return 0;
	 }
	if (a==0 || b==0)
	 cout<<"NO\n";
	else
	 if (s[0]!='a')
	  cout<<"NO\n";
	 else
	  if (c==a || c==b)
	   cout<<"YES\n";
	  else
	   cout<<"NO\n";
}
